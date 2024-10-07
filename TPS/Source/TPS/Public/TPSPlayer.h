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
	UPROPERTY(EditAnywhere, Category=BulletFactory)
	TSubclassOf<class ABullet> BulletFactory;

public:
	// 입력 처리 함수 제작
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* IMC_TPS;
	
	// 카메라 셰이크 블루프린트를 저장할 변수
	UPROPERTY(EditDefaultsOnly, Category = CameraMotion)
	TSubclassOf<class UCameraShakeBase> CameraShake;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Fire;
	// 총알 발사 처리
	void InputFire(const struct FInputActionValue& inputValue);

	// 총알 발사 사운드
	UPROPERTY(EditDefaultsOnly, Category = Sound)
	class USoundBase* BulletSound;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_HandGun;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_SniperGun;

	// 권총(Hand Gun)을 사용 중인지 확인
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = TPS)
	bool bUsingHandGun = true;
	// 소총(Sinper Gun)을 사용 중인지 확인
	bool bUsingSniperGun = true;
	// 권총(Hand Gun)으로 변경
	void ChangeToHandGun(const struct FInputActionValue& inputValue);
	// 소총(Sniper Gun)으로 변경
	void ChangeToSniperGun(const struct FInputActionValue& inputValue);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_Sniper;
	// 스나이퍼 조준 처리 
	void SniperAim(const struct FInputActionValue& inputValue);
	// 스나이퍼 조준 중인지 여부
	bool bSniperAim = false;


	// 크로스헤어, 스나이퍼 위젯 UI 공장을 가지고 있다.
	UPROPERTY(EditDefaultsOnly, Category = CrosshairUI)
	TSubclassOf<class UUserWidget> CrosshairUIfactory;

	UPROPERTY(EditDefaultsOnly)
	class UUserWidget* CrosshairUI;

	UPROPERTY(EditDefaultsOnly, Category = SniperUI)
	TSubclassOf<class UUserWidget> SniperUIfactory;

	UPROPERTY(EditDefaultsOnly)
	class UUserWidget* SniperUI;

	// 총알 파편 효과 공장
	UPROPERTY(EditAnywhere, Category=BulletEffect)
	class UParticleSystem* BulletEffectFactory;

    public:
        // 이동 컴포넌트 등록
        UPROPERTY(VisibleAnywhere, Category = Component)
        class UPlayerBaseComponent* PlayerMoveComp;
};
