// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Enemy.h"
#include "GameFramework/PlayerController.h"
#include "PlayerMoveComp.h"
#include "PlayerFireComp.h"

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
	GetCharacterMovement()->bOrientRotationToMovement = false;

	JumpMaxCount = 2;
	GetCharacterMovement()->AirControl = 1;

	// 권총 (BerettaPistol의 정보)
	// "/Script/Engine.SkeletalMesh'/Game/Resource/Bereta/source/BerettaPistol.BerettaPistol'"

	// 권총을 생성하고 에셋 적용해서 플레이어에 배치하자.
	HandGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BerettaPistol"));
	// 권총을 Mesh에 붙인다.
	HandGun->SetupAttachment(GetMesh(), TEXT("hand_rSocket"));
	HandGun->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempHandGun(TEXT("/Script/Engine.SkeletalMesh'/Game/Resource/Beretta/source/BerettaPistol.BerettaPistol'"));

	if (tempHandGun.Succeeded())
	{
		HandGun->SetSkeletalMesh(tempHandGun.Object);
		HandGun->SetRelativeLocationAndRotation(FVector(-14.4f, 6.6f, 13.2f),FRotator(-4.8f, 41.1f, -16.7f));
		HandGun->SetRelativeScale3D(FVector(2.f));
		// 플레이어 애니메이션 동작에 맞게 재설정
		// Location (X=-14.355527,Y=6.552245,Z=13.188408)
		// Rotation (Pitch=-4.752025,Yaw=41.104528,Roll=-16.704775)
		// Scale (X=2.000000,Y=2.000000,Z=2.000000)
	}

	// 스나이퍼 건을 생성해서 Mesh에 붙인다.
	SniperGun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CheyTacRifle"));
	SniperGun->SetupAttachment(GetMesh(), TEXT("hand_rSocket"));
	SniperGun->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 에셋도 로드해서 적용한다.
	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempSniperGun(TEXT("/Script/Engine.SkeletalMesh'/Game/Resource/CheyTac/source/model.model'"));

	if (tempSniperGun.Succeeded())
	{
		SniperGun->SetSkeletalMesh(tempSniperGun.Object);
		SniperGun->SetRelativeLocationAndRotation(FVector(-19.4f, -5.2f, 8.8f), FRotator(7.5f, 112.4f, -10.6f));
		SniperGun->SetRelativeScale3D(FVector(0.011f));
	}
	// 플레이어 애니메이션 동작에 맞게 재설정
	// Location (X=-19.383786,Y=-5.207941,Z=8.779197)
	// Rotation (Pitch=7.518189,Yaw=112.364942,Roll=-10.632629)
	// Scale (X = 0.011000, Y = 0.011000, Z = 0.011000)

    // 플레이어 이동 컴포넌트 추가
    PlayerMoveComp = CreateDefaultSubobject<UPlayerMoveComp>(TEXT("PlayerMoveComp"));
    // 플레이어 공격 컴포넌트 추가
    PlayerFireComp = CreateDefaultSubobject<UPlayerFireComp>(TEXT("PlayerFireComp"));
}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();

    auto pc = Cast<APlayerController>(Controller);
    if (pc)
    {
        auto subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
        if (subsystem)
        {
            subsystem->AddMappingContext(IMC_TPS, 0);
        }
    }
}

// Called every frame
void ATPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// 입력 함수들을 모두 연결

	auto PlayerInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (PlayerInput)
	{
        // 컴포넌트에서 입력 바인딩 처리를 할 수 있게 호출
        PlayerMoveComp->SetupInputBinding(PlayerInput);
        PlayerFireComp->SetupInputBinding(PlayerInput);
	}
}

