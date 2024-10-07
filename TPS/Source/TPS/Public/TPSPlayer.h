// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSPlayer.generated.h"

UCLASS()
class TPS_API ATPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 컴포넌트 - Spring Arm, Camera
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UCameraComponent* CameraComp;

	// 컴포넌트 - Weapon (권총)
	UPROPERTY(EditAnywhere, Category=Weapon)
	class USkeletalMeshComponent* HandGun;

	// 컴포넌트 - Weapon (소총)
	UPROPERTY(EditAnywhere, Category = Weapon)
	class USkeletalMeshComponent* SniperGun;

public:
	// 입력 처리 함수 제작
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* IMC_TPS;
	
public:
    // 이동 컴포넌트 등록
    UPROPERTY(VisibleAnywhere, Category = Component)
    class UPlayerBaseComponent* PlayerMoveComp;
    // 공격 컴포넌트 등록
    UPROPERTY(VisibleAnywhere, Category = Component)
    class UPlayerBaseComponent* PlayerFireComp;
};
