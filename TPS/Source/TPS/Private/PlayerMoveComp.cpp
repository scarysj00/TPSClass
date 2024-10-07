// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMoveComp.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

UPlayerMoveComp::UPlayerMoveComp()
{
    // Tick 함수가 호출되도록 처리
    PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerMoveComp::BeginPlay()
{
    Super::BeginPlay();

    // 초기 속도를 걷기로 설정
    // GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
    MoveComp->MaxWalkSpeed = WalkSpeed;
}

void UPlayerMoveComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    PlayerMove();
}

void UPlayerMoveComp::SetupInputBinding(UEnhancedInputComponent* PlayerInput)
{
    PlayerInput->BindAction(IA_Turn, ETriggerEvent::Triggered, this, &UPlayerMoveComp::Turn);
    PlayerInput->BindAction(IA_LookUp, ETriggerEvent::Triggered, this, &UPlayerMoveComp::LookUp);
    PlayerInput->BindAction(IA_Move, ETriggerEvent::Triggered, this, &UPlayerMoveComp::Move);

    PlayerInput->BindAction(IA_Jump, ETriggerEvent::Started, this, &UPlayerMoveComp::InputJump);
    // 뛰기 애니메이션
    PlayerInput->BindAction(IA_Run, ETriggerEvent::Started, this, &UPlayerMoveComp::InputRun);
    PlayerInput->BindAction(IA_Run, ETriggerEvent::Completed, this, &UPlayerMoveComp::InputRun);
}

void UPlayerMoveComp::Turn(const FInputActionValue& inputValue)
{
    float value = inputValue.Get<float>();
    Me->AddControllerYawInput(value);
}

void UPlayerMoveComp::LookUp(const FInputActionValue& inputValue)
{
    float value = inputValue.Get<float>();
    Me->AddControllerPitchInput(value);
}

void UPlayerMoveComp::Move(const FInputActionValue& inputValue)
{
    FVector2D value = inputValue.Get<FVector2D>();
    // 상하 입력 처리
    Direction.X = value.X;
    // 좌우 입력 처리
    Direction.Y = value.Y;
}

void UPlayerMoveComp::PlayerMove()
{
    Direction = FTransform(Me->GetControlRotation()).TransformVector(Direction);
    // 등속 운동 공식 : P (이동할 위치) = P0 (현재 위치) + V (속도 * 방향) * T (시간)
    /*FVector P0 = GetActorLocation();
    FVector VT = Direction * WalkSpeed * DeltaTime;
    FVector P = P0 + VT;
    SetActorLocation(P);*/
    Me->AddMovementInput(Direction);
    Direction = FVector::ZeroVector;
}

void UPlayerMoveComp::InputJump(const FInputActionValue& inputValue)
{
    Me->Jump();
}

void UPlayerMoveComp::InputRun()
{
    auto Movement = Me->GetCharacterMovement();
    // 만약, 현재 달리기 모드라면
    if (Movement->MaxWalkSpeed > WalkSpeed)
    {
        // 걷기 속도로 전환
        Movement->MaxWalkSpeed = WalkSpeed;
    }
    else
    {
        Movement->MaxWalkSpeed = RunSpeed;
    }
}



