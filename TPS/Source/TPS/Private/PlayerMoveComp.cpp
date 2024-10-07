// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMoveComp.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

UPlayerMoveComp::UPlayerMoveComp()
{
    // Tick �Լ��� ȣ��ǵ��� ó��
    PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerMoveComp::BeginPlay()
{
    Super::BeginPlay();

    // �ʱ� �ӵ��� �ȱ�� ����
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
    // �ٱ� �ִϸ��̼�
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
    // ���� �Է� ó��
    Direction.X = value.X;
    // �¿� �Է� ó��
    Direction.Y = value.Y;
}

void UPlayerMoveComp::PlayerMove()
{
    Direction = FTransform(Me->GetControlRotation()).TransformVector(Direction);
    // ��� � ���� : P (�̵��� ��ġ) = P0 (���� ��ġ) + V (�ӵ� * ����) * T (�ð�)
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
    // ����, ���� �޸��� �����
    if (Movement->MaxWalkSpeed > WalkSpeed)
    {
        // �ȱ� �ӵ��� ��ȯ
        Movement->MaxWalkSpeed = WalkSpeed;
    }
    else
    {
        Movement->MaxWalkSpeed = RunSpeed;
    }
}



