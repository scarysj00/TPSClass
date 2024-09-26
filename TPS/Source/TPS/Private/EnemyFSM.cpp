// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFSM.h"
#include "TPSPlayer.h"
#include "Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "EnemyAnim.h"
#include "AIController.h"

// Sets default values for this component's properties
UEnemyFSM::UEnemyFSM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyFSM::BeginPlay()
{
	Super::BeginPlay();

	// 월드에서 ATPSPlayer 타깃 찾아오기
	auto Actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATPSPlayer::StaticClass());
	// ATPSPlayer 타입으로 캐스팅
	Target = Cast<ATPSPlayer>(Actor);
	// 소유 객체 가져오기
	Me = Cast<AEnemy>(GetOwner());
    
    // 사용 중인 UEnemyAnim 가져오기
    Anim = Cast<UEnemyAnim>(Me->GetMesh()->GetAnimInstance());

    // AAIController 할당
    // AI = Cast<AAIController>(Me->GetController());
}


// Called every frame
void UEnemyFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 실행 창에 상태 메시지 출력
	FString LogMsg = UEnum::GetValueAsString(mState);
	GEngine->AddOnScreenDebugMessage(0, 1, FColor::Cyan, LogMsg);

	switch (mState)
	{
	case EEnemyState::Idle:
		IdleState();
		break;
	case EEnemyState::Move:
		MoveState();
		break;
	case EEnemyState::Attack:
		AttackState();
		break;
	case EEnemyState::Damage:
		DamageState();
		break;
	case EEnemyState::Die:
		DieState();
		break;
	}
}

void UEnemyFSM::IdleState()
{
	// 일정 시간 기다렸다가 이동 상태로 전환하고 싶다.
	// 1. 시간이 흘렀으니까
	CurrentTime += GetWorld()->DeltaTimeSeconds;
	// 2. 만약 경과 시간이 대기 시간을 초과했다면
	if (CurrentTime > IdleDelayTime)
	{
		// 3. 이동 상태로 전환하고 싶다
		mState = EEnemyState::Move;
		// 경과 시간 초기화
		CurrentTime = 0;

        // 애니메이션 상태 동기화
        Anim->AnimState = mState;
	}
}

void UEnemyFSM::MoveState()
{
	// 타깃의 방향으로 이동하고 싶다.
	// 1. 타깃 목적지가 필요하다.
	FVector Destination = Target->GetActorLocation();
	// 2. 방향이 필요하다.
	FVector Dir = Destination - Me->GetActorLocation();
	// 3. 방향으로 이동하고 싶다.
	Me->AddMovementInput(Dir.GetSafeNormal());
    // AI->MoveToLocation(Destination);

	// 타깃과 가까워지면 공격 상태로 전환하고 싶다.
	// 1. 만약 거리가 공격 범위 안에 들어오면
	if (Dir.Size() < AttackRange)
	{
		// 2. 공격 상태로 전환하고 싶다.
		mState = EEnemyState::Attack;
        CurrentTime = 0;
        // AI->StopMovement();

        // 애니메이션 상태 동기화
        Anim->AnimState = mState;
        // 공격 애니메이션 재생 활성화
        Anim->bAttackPlay = true;
        // 공격 상태 전환 시 대기 시간이 바로 종료
        CurrentTime = AttackDelayTime;
	}
}

void UEnemyFSM::AttackState()
{
	// 일정 시간에 한 번씩 공격하고 싶다.
	// 1. 시간이 흘러야 한다.
	CurrentTime += GetWorld()->DeltaTimeSeconds;
	// 2. 공격 시간이 됐으니까
	if (CurrentTime > AttackDelayTime)
	{
		// 3. 공격하고 싶다.
		UE_LOG(LogTemp, Warning, TEXT("Attack!!!!"));
        // 경과 시간 초기화
        CurrentTime = 0;
        Anim->bAttackPlay = true;
	}

	// 타깃이 공격 범위를 벗어나면 상태를 이동으로 전환하고 싶다.
	// 1. 타깃과의 거리가 필요하다.
	float Distance = FVector::Distance(Target->GetActorLocation(), Me->GetActorLocation());
	// 2. 타깃과의 거리가 공격 범위를 벗어났으니
	if (Distance > AttackRange)
	{
		// 3. 상태를 이동으로 전환하고 싶다.
		mState = EEnemyState::Move;
        // 애니메이션 상태 동기화
        Anim->AnimState = mState;
	}
}

void UEnemyFSM::DamageState()
{
	// 일정 시간 기다렸다가 상태를 대기로 변경하고 싶다.
	// 1. 시간이 흘렀으니까
	CurrentTime += GetWorld()->DeltaTimeSeconds;
	// 2. 만약 경과 시간이 대기 시간을 초과했다면
	if (CurrentTime > DamageDelayTime)
	{
		// 3. 대기 상태로 전환하고 싶다.
		mState = EEnemyState::Idle;
		// 경과 시간 초기화
		CurrentTime = 0;
        // 애니메이션 상태 동기화
        Anim->AnimState = mState;
	}
}

void UEnemyFSM::DieState()
{
	// 아직 죽음 애니메이션이 끝나지 않았다면
    // 바닥으로 내려가지 않도록 처리
    if (Anim -> bDieDone == false)
    {
        return;
    }
    
    // 계속 아래로 내려간다
	// 등속 운동 공식 P = P0 + VT
	FVector P0 = Me->GetActorLocation();
	FVector VT = FVector::DownVector * DieSpeed * GetWorld()->DeltaTimeSeconds;
	FVector P = P0 + VT;
	Me->SetActorLocation(P);

	// 만약 2미터 이상 내려왔다면
	if (P.Z < -200.0f)
	{
		// 제거시킨다.
		Me->Destroy();
	}
}

void UEnemyFSM::OnDamageProcess()
{
	// Me->Destroy();

    
    // 체력 감소
	HP--;
	// 만약 체력이 남아있다면
	if (HP > 0)
	{
		// 상태를 피격으로 전환
		mState = EEnemyState::Damage;

        CurrentTime = 0;
        // AI->StopMovement();
        // 피격 애니메이션 재생
        int32 index = FMath::RandRange(0, 1);
        FString SectionName = FString::Printf(TEXT("Damage%d"), index);
        Anim->PlayDamageAnim(FName(*SectionName));
	}
	// 그렇지 않다면
	else
	{
		// 상태를 죽음으로 전환
		mState = EEnemyState::Die;

		// 캡슐 컴포넌트 충돌체 비활성화
		Me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        // 죽음 애니메이션 재생
        Anim->PlayDamageAnim(TEXT("Die"));
	}
    // 애니메이션 상태 동기화
    Anim->AnimState = mState;
}

