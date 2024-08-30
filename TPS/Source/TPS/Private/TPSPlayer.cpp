// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Bullet.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyFSM.h"

// Sets default values
ATPSPlayer::ATPSPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Spring Arm 을 생성해서 Root 에 붙인다
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	// Spring Arm -> Target Arm Length : 400
	SpringArmComp->TargetArmLength = 300;
	// 위치 (X = 0.000000, Y = 50.000000, Z = 80.000000) 
	SpringArmComp->SetRelativeLocation(FVector(0, 50, 80));

	// Camera 를 생성해서 Spring Arm 에 붙인다.
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	// Mesh에 3D 에셋을 로드해서 넣어준다.
	// 생성자 도우미를 이용해서 스켈레탈 메쉬를 로드한다.
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn.SKM_Quinn'"));
	// (설명) 템플릿이란 변수를 만들면서 생성자 함수를 통해서 이 주소를 로드하게 된다.

	// 만약, 로드가 성공했다면
	if (tempMesh.Succeeded())
	{
		// 메시에 넣는다
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
		// 메시를 넣은 다음에 캐릭터의 위치 변경과 회전을 했다.
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
	}

	bUseControllerRotationYaw = true;
	SpringArmComp->bUsePawnControlRotation = true;
	CameraComp->bUsePawnControlRotation = false;
	// 카메라는 스프링 암을 따라가기 때문에 카메라 회전은 체크 비활성화
	GetCharacterMovement()->bOrientRotationToMovement = true;

	JumpMaxCount = 2;
	GetCharacterMovement()->AirControl = 1;

	// 권총 (BerettaPistol의 정보)
	// (X=-5.077071,Y=51.940998,Z=140.000000)
	// (Pitch=0.000000,Yaw=-70.000000,Roll=0.000000)
	// (X=2.000000,Y=2.000000,Z=2.000000)
	// "/Script/Engine.SkeletalMesh'/Game/Resource/Bereta/source/BerettaPistol.BerettaPistol'"

	// 권총을 생성하고 에셋 적용해서 플레이어에 배치하자.
	HandGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BerettaPistol"));
	// 권총을 Mesh에 붙인다.
	HandGun->SetupAttachment(GetMesh(), TEXT("FirePosition"));
	HandGun->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempHandGun(TEXT("/Script/Engine.SkeletalMesh'/Game/Resource/Beretta/source/BerettaPistol.BerettaPistol'"));

	if (tempHandGun.Succeeded())
	{
		HandGun->SetSkeletalMesh(tempHandGun.Object);
		HandGun->SetRelativeLocationAndRotation(FVector(-5.f, 52.f, 140.f),FRotator(0, -60, 0));
		HandGun->SetRelativeScale3D(FVector(2.f));
	}

	// 스나이퍼 건을 생성해서 Mesh에 붙인다.
	SniperGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CheyTacRifle"));
	SniperGun->SetupAttachment(GetMesh(), TEXT("ShotPosition"));
	SniperGun->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 에셋도 로드해서 적용한다.
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempSniperGun(TEXT("/Script/Engine.SkeletalMesh'/Game/Resource/CheyTac/source/model.model'"));

	if (tempSniperGun.Succeeded())
	{
		SniperGun->SetSkeletalMesh(tempSniperGun.Object);
		SniperGun->SetRelativeLocationAndRotation(FVector(-14.6f, 63.7f, 147.f), FRotator(0, 0, 0));
		SniperGun->SetRelativeScale3D(FVector(0.015f));
	}
	// Location (X=-14.600000,Y=63.700000,Z=147.000000)
	// Rotation (Pitch = 0.000000, Yaw = 0.000000, Roll = 0.000000)
	// Scale (X = 0.015000, Y = 0.015000, Z = 0.015000)0,
}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();

	// 시작할 때 두 개의 위젯을 생성한다.
	// 크로스헤어 UI 위젯 인스턴스 생성
	CrosshairUI = CreateWidget(GetWorld(), CrosshairUIfactory);
	// 스나이퍼 UI 위젯 인스턴스 생성
	SniperUI = CreateWidget(GetWorld(), SniperUIfactory);
	// 일반 조준 모드 CrosshairUI 화면에 노출
	// CrosshairUI->AddToViewport();


	//// 화면에 나오게 한다.
	//CrosshairUI->AddToViewport();
	//SniperUI->AddToViewport();
	//// 화면에서 안보이게 한다.
	//CrosshairUI->RemoveFromParent();
	//SniperUI->RemoveFromParent();

	auto pc = Cast<APlayerController>(Controller);
	if (pc)
	{
		auto subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
		if (subsystem)
		{
			subsystem->AddMappingContext(IMC_TPS, 0);
		}
	}
	// 소총(Sniper Gun)으로 기본 설정
	ChangeToSniperGun(FInputActionValue());

}

// Called every frame
void ATPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerMove();
}

// Called to bind functionality to input
void ATPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// 입력 함수들을 모두 연결

	auto PlayerInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (PlayerInput)
	{
		PlayerInput->BindAction(IA_Turn, ETriggerEvent::Triggered, this, &ATPSPlayer::Turn);
		PlayerInput->BindAction(IA_LookUp, ETriggerEvent::Triggered, this, &ATPSPlayer::LookUp);
		PlayerInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ATPSPlayer::Move);
		PlayerInput->BindAction(IA_Jump, ETriggerEvent::Started, this, &ATPSPlayer::InputJump);
		
		PlayerInput->BindAction(IA_Fire, ETriggerEvent::Started, this, &ATPSPlayer::InputFire);
		// 총 교체 이벤트 처리
		PlayerInput->BindAction(IA_HandGun, ETriggerEvent::Started, this, &ATPSPlayer::ChangeToHandGun);
		PlayerInput->BindAction(IA_SniperGun, ETriggerEvent::Started, this, &ATPSPlayer::ChangeToSniperGun);
		// 스나이퍼 조준 모드
		PlayerInput->BindAction(IA_Sniper, ETriggerEvent::Started, this, &ATPSPlayer::SniperAim);
		PlayerInput->BindAction(IA_Sniper, ETriggerEvent::Completed, this, &ATPSPlayer::SniperAim);

	}
}

void ATPSPlayer::Turn(const FInputActionValue& inputValue)
{
	float value = inputValue.Get<float>();
	AddControllerYawInput(value);
}

void ATPSPlayer::LookUp(const FInputActionValue& inputValue)
{
	float value = inputValue.Get<float>();
	AddControllerPitchInput(value);
}

void ATPSPlayer::Move(const FInputActionValue& inputValue)
{
	FVector2D value = inputValue.Get<FVector2D>();
	// 상하 입력 처리
	Direction.X = value.X;
	// 좌우 입력 처리
	Direction.Y = value.Y;
}

void ATPSPlayer::InputJump(const FInputActionValue& inputValue)
{
	Jump();
}

void ATPSPlayer::PlayerMove()
{
	Direction = FTransform(GetControlRotation()).TransformVector(Direction);
	// 등속 운동 공식 : P (이동할 위치) = P0 (현재 위치) + V (속도 * 방향) * T (시간)
	/*FVector P0 = GetActorLocation();
	FVector VT = Direction * WalkSpeed * DeltaTime;
	FVector P = P0 + VT;
	SetActorLocation(P);*/
	AddMovementInput(Direction);
	Direction = FVector::ZeroVector;
}

void ATPSPlayer::InputFire(const FInputActionValue& inputValue)
{
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
		Params.AddIgnoredActor(this);
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
		if (Enemy)
		{
			auto EnemyFSM = Cast<UEnemyFSM>(Enemy);
			EnemyFSM->OnDamageProcess();
		}
	}	
}

void ATPSPlayer::ChangeToHandGun(const FInputActionValue& inputValue)
{
	// 권총(Hand Gun) 사용
	bUsingHandGun = true;
	SniperGun->SetVisibility(false);
	HandGun->SetVisibility(true);
	//CrosshairUI->AddToViewport();
	//SniperUI->RemoveFromParent();
	//CameraComp->FieldOfView = 90;
}
void ATPSPlayer::ChangeToSniperGun(const FInputActionValue& inputValue)
{
	// 소총(Sniper Gun) 사용
	bUsingHandGun = false;
	SniperGun->SetVisibility(true);
	HandGun->SetVisibility(false);
	//SniperUI->AddToViewport();
	//CrosshairUI->RemoveFromParent();
	//CameraComp->FieldOfView = 45;
}

void ATPSPlayer::SniperAim(const struct FInputActionValue& inputValue)
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
