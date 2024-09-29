// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "EnemyFSM.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Meshes/Khaimera.Khaimera'"));
	if (tempMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -87), FRotator(0, -90, 0));
        GetMesh()->SetRelativeScale3D(FVector(0.84f));
	}

	// EnemyFSM 을 생성한다.
	EnemyFSM = CreateDefaultSubobject<UEnemyFSM>(TEXT("EnemyFSM"));

    // 애니메이션 블루프린트 할당하기
    ConstructorHelpers::FClassFinder<UAnimInstance> tempClass(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprint/ABP_Enemy.ABP_Enemy_C'"));
    if (tempClass.Succeeded())
    {
        GetMesh()->SetAnimInstanceClass(tempClass.Class);
    }

    // 월드에 배치되거나 스폰될 때 
    // 자동으로 AIController부터 Possess 될 수 있게 설정
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    HPComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPComp"));
    HPComp->SetupAttachment(RootComponent);
    // WBP_EnemyHP를 로드해서 HPComp의 위젯으로 설정한다.
    ConstructorHelpers::FClassFinder<UUserWidget> tempHP(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/WBP_EnemyHP.WBP_EnemyHP_C'"));
    if (tempHP.Succeeded())
    {
        HPComp->SetWidgetClass(tempHP.Class);
        // Draw Size = 150, 20
        HPComp->SetDrawSize(FVector2D(150, 20));
        // Location = 0, 0, 90
        HPComp->SetRelativeLocation(FVector(0, 0, 90));
        // 충돌체 설정
        HPComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }

    // 캡슐 컴포넌트와 메시 컴포넌트의 충돌 채널을 설정한다.
    // 캡슐 컴포넌트 Visibility : Block / Camera : Ingnore
    // 메시 컴포넌트 Visibility : Ingore / Camera : Ingnore

    UCapsuleComponent* Cap = GetCapsuleComponent();
    auto EMesh = GetMesh();
    Cap->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    Cap->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

    EMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
    EMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    // UKismetMathLibrary::FindLookAtRotation를 이용해서 HPComp를 회전한다.
    FVector Start = HPComp->K2_GetComponentLocation();
    FVector Target = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();

    FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(Start, Target);

    HPComp->SetWorldRotation(NewRotation);
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

