// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFireComp.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Bullet.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyFSM.h"
#include "PlayerAnim.h"

UPlayerFireComp::UPlayerFireComp()
{
    // 총알 사운드 가져오기
    ConstructorHelpers::FObjectFinder<USoundBase> tempSound(TEXT("/Script/Engine.SoundWave'/Game/Resource/Sound/SoundRifle.SoundRifle'"));

    if (tempSound.Succeeded())
    {
        BulletSound = tempSound.Object;
    }
}

void UPlayerFireComp::BeginPlay()
{
    Super::BeginPlay();

    CameraComp = Me->CameraComp;
    HandGun = Me->HandGun;
    SniperGun = Me->SniperGun;
    
    // 시작할 때 두 개의 위젯을 생성한다.
    // 크로스헤어 UI 위젯 인스턴스 생성
    CrosshairUI = CreateWidget(GetWorld(), CrosshairUIfactory);
    // 스나이퍼 UI 위젯 인스턴스 생성
    SniperUI = CreateWidget(GetWorld(), SniperUIfactory);
    // 일반 조준 모드 CrosshairUI 화면에 노출
    CrosshairUI->AddToViewport();

    // 소총(Sniper Gun)으로 기본 설정
    ChangeToSniperGun(FInputActionValue());
}

void UPlayerFireComp::ChangeToHandGun(const FInputActionValue& inputValue)
{
    // 권총(Hand Gun) 사용
    bUsingHandGun = true;
    SniperGun->SetVisibility(false);
    HandGun->SetVisibility(true);
    //CrosshairUI->AddToViewport();
    //SniperUI->RemoveFromParent();
    //CameraComp->FieldOfView = 90;
}
void UPlayerFireComp::ChangeToSniperGun(const FInputActionValue& inputValue)
{
    // 소총(Sniper Gun) 사용
    bUsingHandGun = false;
    SniperGun->SetVisibility(true);
    HandGun->SetVisibility(false);
    //SniperUI->AddToViewport();
    //CrosshairUI->RemoveFromParent();
    //CameraComp->FieldOfView = 45;
}

void UPlayerFireComp::SniperAim(const struct FInputActionValue& inputValue)
{
    // 스나이퍼 모드가 아닐 경우 처리하지 않는다
    if (bUsingHandGun)
    {
        return;
    }
    // Pressed 입력 처리
    if (bSniperAim == false)
    {
        // 스나이퍼 조준 모드 활성화
        bSniperAim = true;
        // 스나이퍼 조준 UI 등록
        SniperUI->AddToViewport();
        CameraComp->SetFieldOfView(45.0f);
        // 일반 조준 모드 UI 제거
        CrosshairUI->RemoveFromParent();
    }
    // Released 입력 처리
    else
    {
        // 스나이퍼 조준 모드 비활성화
        bSniperAim = false;
        // 스나이퍼 조준 UI 화면에서 제거
        SniperUI->RemoveFromParent();
        CameraComp->SetFieldOfView(90.0f);
        // 일반 조준 모드 UI 표시
        CrosshairUI->AddToViewport();
    }
}

void UPlayerFireComp::SetupInputBinding(UEnhancedInputComponent* PlayerInput)
{
    PlayerInput->BindAction(IA_Fire, ETriggerEvent::Started, this, &UPlayerFireComp::InputFire);
    // 총 교체 이벤트 처리
    PlayerInput->BindAction(IA_HandGun, ETriggerEvent::Started, this, &UPlayerFireComp::ChangeToHandGun);
    PlayerInput->BindAction(IA_SniperGun, ETriggerEvent::Started, this, &UPlayerFireComp::ChangeToSniperGun);
    // 스나이퍼 조준 모드
    PlayerInput->BindAction(IA_Sniper, ETriggerEvent::Started, this, &UPlayerFireComp::SniperAim);
    PlayerInput->BindAction(IA_Sniper, ETriggerEvent::Completed, this, &UPlayerFireComp::SniperAim);
}

void UPlayerFireComp::InputFire(const FInputActionValue& inputValue)
{
    // 총알 발사 사운드 재생
    UGameplayStatics::PlaySound2D(GetWorld(), BulletSound);

    // 카메라 셰이크 재생
    auto CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
    CameraManager->StartCameraShake(CameraShake);

    // 공격 애니메이션 재생
    auto Anim = Cast<UPlayerAnim>(Me->GetMesh()->GetAnimInstance());
    Anim->PlayAttackAnim();

    // 총알을 생성해서 권총의 총구 위치에 배치한다.
    if (bUsingHandGun)
    {
        //bUsingHandGun = true;
        FTransform FirePosition = HandGun->GetSocketTransform(TEXT("FirePosition"));
        GetWorld()->SpawnActor<ABullet>(BulletFactory, FirePosition);
    }
    else if (bUsingSniperGun)
    {
        FTransform ShotPosition = SniperGun->GetSocketTransform(TEXT("ShotPosition"));
        GetWorld()->SpawnActor<ABullet>(BulletFactory, ShotPosition);

        // LineTrace 의 시작 위치
        FVector StartPosition = CameraComp->GetComponentLocation();
        // LineTrace 의 종료 위치
        FVector EndPosition = CameraComp->GetComponentLocation() + CameraComp->GetForwardVector() * 100000;
        // LineTrace 의 충돌 정보를 담을 변수
        FHitResult HitInfo;
        // 충돌 옵션 설정 변수
        FCollisionQueryParams Params;
        // 자기 자신(플레이어)는 충돌에서 제외
        Params.AddIgnoredActor(Me);
        // Channel 필터를 이용한 LineTrace 충돌 검출
        // 충돌 정보, 시작 위치, 종료 위치, 검출 채널, 충돌 옵션
        bool bHit = GetWorld()->LineTraceSingleByChannel(HitInfo, StartPosition, EndPosition, ECC_Visibility, Params);

        // 충돌 처리 -> 총알 파편 효과 재생
        if (bHit)
        {
            // 총알 파편 효과 트랜스폼
            FTransform BulletTransform;
            // 부딪힌 위치 할당
            BulletTransform.SetLocation(HitInfo.ImpactPoint);
            // 총알 파편 효과 인스턴스 생성
            UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletEffectFactory, BulletTransform);
        }

        // 부딪힌 물체의 컴포넌트에 물리가 적용되어 있으면 날려 버리고 싶다.
        auto HitComp = HitInfo.GetComponent();
        // 1. 만약 컴포넌트에 물리가 적용되어 있다면
        if (HitComp && HitComp->IsSimulatingPhysics())
        {
            // 2. 조준한 방향이 필요
            FVector Dir = (EndPosition - StartPosition).GetSafeNormal();
            // 날려버릴 방향
            FVector Force = Dir * HitComp->GetMass() * 500000;
            // 3. 그 방향으로 날리고 싶다.
            HitComp->AddForceAtLocation(Force, HitInfo.ImpactPoint);
        }

        // 부딪힌 대상이 적인지 판단
        auto Enemy = HitInfo.GetActor()->GetDefaultSubobjectByName(TEXT("EnemyFSM"));
        // 맞은 물체가 적이라면
        if (Enemy)
        {
            // 적이 피격 당했다고 알려준다.
            auto EnemyFSM = Cast<UEnemyFSM>(Enemy);
            EnemyFSM->OnDamageProcess(1);
        }
    }
}