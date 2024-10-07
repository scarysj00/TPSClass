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

    // 좌우 회전
    void Turn(const struct FInputActionValue& inputValue);
    // 상하 회전
    void LookUp(const struct FInputActionValue& inputValue);

    virtual void SetupInputBinding(class UEnhancedInputComponent* PlayerInput) override;

public:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Move;

    // 이동 방향
    FVector Direction;

    void Move(const struct FInputActionValue& inputValue);

    // 이동 속도
    UPROPERTY(EditAnywhere, Category = PlayerSetting)
    float WalkSpeed = 300;
    // 달리기 속도
    UPROPERTY(EditAnywhere, Category = PlayerSetting)
    float RunSpeed = 600;

    // 플레이어 이동 처리
    void PlayerMove();

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Jump;
    // 점프 입력 처리
    void InputJump(const struct FInputActionValue& inputValue);

    // 플레이어 뛰기
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Run;
    void InputRun();

};
