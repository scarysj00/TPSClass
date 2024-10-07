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
    // �Ѿ� ���� ��������
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
    
    // ������ �� �� ���� ������ �����Ѵ�.
    // ũ�ν���� UI ���� �ν��Ͻ� ����
    CrosshairUI = CreateWidget(GetWorld(), CrosshairUIfactory);
    // �������� UI ���� �ν��Ͻ� ����
    SniperUI = CreateWidget(GetWorld(), SniperUIfactory);
    // �Ϲ� ���� ��� CrosshairUI ȭ�鿡 ����
    CrosshairUI->AddToViewport();

    // ����(Sniper Gun)���� �⺻ ����
    ChangeToSniperGun(FInputActionValue());
}

void UPlayerFireComp::ChangeToHandGun(const FInputActionValue& inputValue)
{
    // ����(Hand Gun) ���
    bUsingHandGun = true;
    SniperGun->SetVisibility(false);
    HandGun->SetVisibility(true);
    //CrosshairUI->AddToViewport();
    //SniperUI->RemoveFromParent();
    //CameraComp->FieldOfView = 90;
}
void UPlayerFireComp::ChangeToSniperGun(const FInputActionValue& inputValue)
{
    // ����(Sniper Gun) ���
    bUsingHandGun = false;
    SniperGun->SetVisibility(true);
    HandGun->SetVisibility(false);
    //SniperUI->AddToViewport();
    //CrosshairUI->RemoveFromParent();
    //CameraComp->FieldOfView = 45;
}

void UPlayerFireComp::SniperAim(const struct FInputActionValue& inputValue)
{
    // �������� ��尡 �ƴ� ��� ó������ �ʴ´�
    if (bUsingHandGun)
    {
        return;
    }
    // Pressed �Է� ó��
    if (bSniperAim == false)
    {
        // �������� ���� ��� Ȱ��ȭ
        bSniperAim = true;
        // �������� ���� UI ���
        SniperUI->AddToViewport();
        CameraComp->SetFieldOfView(45.0f);
        // �Ϲ� ���� ��� UI ����
        CrosshairUI->RemoveFromParent();
    }
    // Released �Է� ó��
    else
    {
        // �������� ���� ��� ��Ȱ��ȭ
        bSniperAim = false;
        // �������� ���� UI ȭ�鿡�� ����
        SniperUI->RemoveFromParent();
        CameraComp->SetFieldOfView(90.0f);
        // �Ϲ� ���� ��� UI ǥ��
        CrosshairUI->AddToViewport();
    }
}

void UPlayerFireComp::SetupInputBinding(UEnhancedInputComponent* PlayerInput)
{
    PlayerInput->BindAction(IA_Fire, ETriggerEvent::Started, this, &UPlayerFireComp::InputFire);
    // �� ��ü �̺�Ʈ ó��
    PlayerInput->BindAction(IA_HandGun, ETriggerEvent::Started, this, &UPlayerFireComp::ChangeToHandGun);
    PlayerInput->BindAction(IA_SniperGun, ETriggerEvent::Started, this, &UPlayerFireComp::ChangeToSniperGun);
    // �������� ���� ���
    PlayerInput->BindAction(IA_Sniper, ETriggerEvent::Started, this, &UPlayerFireComp::SniperAim);
    PlayerInput->BindAction(IA_Sniper, ETriggerEvent::Completed, this, &UPlayerFireComp::SniperAim);
}

void UPlayerFireComp::InputFire(const FInputActionValue& inputValue)
{
    // �Ѿ� �߻� ���� ���
    UGameplayStatics::PlaySound2D(GetWorld(), BulletSound);

    // ī�޶� ����ũ ���
    auto CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
    CameraManager->StartCameraShake(CameraShake);

    // ���� �ִϸ��̼� ���
    auto Anim = Cast<UPlayerAnim>(Me->GetMesh()->GetAnimInstance());
    Anim->PlayAttackAnim();

    // �Ѿ��� �����ؼ� ������ �ѱ� ��ġ�� ��ġ�Ѵ�.
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

        // LineTrace �� ���� ��ġ
        FVector StartPosition = CameraComp->GetComponentLocation();
        // LineTrace �� ���� ��ġ
        FVector EndPosition = CameraComp->GetComponentLocation() + CameraComp->GetForwardVector() * 100000;
        // LineTrace �� �浹 ������ ���� ����
        FHitResult HitInfo;
        // �浹 �ɼ� ���� ����
        FCollisionQueryParams Params;
        // �ڱ� �ڽ�(�÷��̾�)�� �浹���� ����
        Params.AddIgnoredActor(Me);
        // Channel ���͸� �̿��� LineTrace �浹 ����
        // �浹 ����, ���� ��ġ, ���� ��ġ, ���� ä��, �浹 �ɼ�
        bool bHit = GetWorld()->LineTraceSingleByChannel(HitInfo, StartPosition, EndPosition, ECC_Visibility, Params);

        // �浹 ó�� -> �Ѿ� ���� ȿ�� ���
        if (bHit)
        {
            // �Ѿ� ���� ȿ�� Ʈ������
            FTransform BulletTransform;
            // �ε��� ��ġ �Ҵ�
            BulletTransform.SetLocation(HitInfo.ImpactPoint);
            // �Ѿ� ���� ȿ�� �ν��Ͻ� ����
            UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletEffectFactory, BulletTransform);
        }

        // �ε��� ��ü�� ������Ʈ�� ������ ����Ǿ� ������ ���� ������ �ʹ�.
        auto HitComp = HitInfo.GetComponent();
        // 1. ���� ������Ʈ�� ������ ����Ǿ� �ִٸ�
        if (HitComp && HitComp->IsSimulatingPhysics())
        {
            // 2. ������ ������ �ʿ�
            FVector Dir = (EndPosition - StartPosition).GetSafeNormal();
            // �������� ����
            FVector Force = Dir * HitComp->GetMass() * 500000;
            // 3. �� �������� ������ �ʹ�.
            HitComp->AddForceAtLocation(Force, HitInfo.ImpactPoint);
        }

        // �ε��� ����� ������ �Ǵ�
        auto Enemy = HitInfo.GetActor()->GetDefaultSubobjectByName(TEXT("EnemyFSM"));
        // ���� ��ü�� ���̶��
        if (Enemy)
        {
            // ���� �ǰ� ���ߴٰ� �˷��ش�.
            auto EnemyFSM = Cast<UEnemyFSM>(Enemy);
            EnemyFSM->OnDamageProcess(1);
        }
    }
}