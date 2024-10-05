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

	// EnemyFSM �� �����Ѵ�.
	EnemyFSM = CreateDefaultSubobject<UEnemyFSM>(TEXT("EnemyFSM"));

    // �ִϸ��̼� �������Ʈ �Ҵ��ϱ�
    ConstructorHelpers::FClassFinder<UAnimInstance> tempClass(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprint/ABP_Enemy.ABP_Enemy_C'"));
    if (tempClass.Succeeded())
    {
        GetMesh()->SetAnimInstanceClass(tempClass.Class);
    }

    // ���忡 ��ġ�ǰų� ������ �� 
    // �ڵ����� AIController���� Possess �� �� �ְ� ����
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    HPComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPComp"));
    HPComp->SetupAttachment(RootComponent);
    // WBP_EnemyHP�� �ε��ؼ� HPComp�� �������� �����Ѵ�.
    ConstructorHelpers::FClassFinder<UUserWidget> tempHP(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/WBP_EnemyHP.WBP_EnemyHP_C'"));
    if (tempHP.Succeeded())
    {
        HPComp->SetWidgetClass(tempHP.Class);
        // Draw Size = 150, 20
        HPComp->SetDrawSize(FVector2D(150, 20));
        // Location = 0, 0, 90
        HPComp->SetRelativeLocation(FVector(0, 0, 90));
        // �浹ü ����
        HPComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }

    // ĸ�� ������Ʈ�� �޽� ������Ʈ�� �浹 ä���� �����Ѵ�.
    // ĸ�� ������Ʈ Visibility : Block / Camera : Ingnore
    // �޽� ������Ʈ Visibility : Ingore / Camera : Ingnore

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

    // EnemyFSM�� ü���� �ʱ�ȭ �ϰ� �ʹ�.
    EnemyFSM->InitHP();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    // UKismetMathLibrary::FindLookAtRotation�� �̿��ؼ� HPComp�� ȸ���Ѵ�.
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

