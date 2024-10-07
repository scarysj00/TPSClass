// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "PlayerMoveComp.generated.h"

UCLASS()
class TPS_API UPlayerMoveComp : public UPlayerBaseComponent
{
	GENERATED_BODY()

public:
    UPlayerMoveComp();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_LookUp; 
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Turn;

    // �¿� ȸ��
    void Turn(const struct FInputActionValue& inputValue);
    // ���� ȸ��
    void LookUp(const struct FInputActionValue& inputValue);

    virtual void SetupInputBinding(class UEnhancedInputComponent* PlayerInput) override;

public:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Move;

    // �̵� ����
    FVector Direction;

    void Move(const struct FInputActionValue& inputValue);

    // �̵� �ӵ�
    UPROPERTY(EditAnywhere, Category = PlayerSetting)
    float WalkSpeed = 300;
    // �޸��� �ӵ�
    UPROPERTY(EditAnywhere, Category = PlayerSetting)
    float RunSpeed = 600;

    // �÷��̾� �̵� ó��
    void PlayerMove();

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Jump;
    // ���� �Է� ó��
    void InputJump(const struct FInputActionValue& inputValue);

    // �÷��̾� �ٱ�
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Run;
    void InputRun();

};
