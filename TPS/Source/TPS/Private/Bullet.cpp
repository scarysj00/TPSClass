// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	// 1. 충돌체를 Root Component 로 만들고 반지름은 12.5f 로 설정한다.
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->SetSphereRadius(13.f);
	// Collision Comp - Collision 설정
	CollisionComp->SetCollisionProfileName(TEXT("BlockAll"));

	// 2. 외관을 충돌체에 붙이고 크기는 0.25f 로 설정한다.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(CollisionComp);
	MeshComp->SetRelativeScale3D(FVector(0.1f));
	// Mesh Comp - Collision 설정 
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	// 3. Move Component 를 만들고 속력과 바운스를 설정한다.
	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComp"));
	MovementComp->InitialSpeed = 5000.f;
	MovementComp->MaxSpeed = 5000.f;
	MovementComp->bShouldBounce = true;
	MovementComp->Bounciness = .3f;
	// 총알 인스턴스 생명 주기
	// InitialLifeSpan = 2.0f;

	MovementComp->SetUpdatedComponent(CollisionComp);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle DeathTimer;
	GetWorld()->GetTimerManager().SetTimer(DeathTimer, this, &ABullet::Die, 2.0f, false);	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::Die()
{
	Destroy();
}

