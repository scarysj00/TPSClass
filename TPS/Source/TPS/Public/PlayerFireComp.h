// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "PlayerFireComp.generated.h"

UCLASS()
class TPS_API UPlayerFireComp : public UPlayerBaseComponent
{
	GENERATED_BODY()

public:
    UPlayerFireComp();

    virtual void BeginPlay() override;

    virtual void SetupInputBinding(class UEnhancedInputComponent* PlayerInput) override;

public:
    UPROPERTY()
    class UCameraComponent* CameraComp;

    // ������Ʈ - Weapon (����)
    UPROPERTY()
    class USkeletalMeshComponent* HandGun;

    // ������Ʈ - Weapon (����)
    UPROPERTY()
    class USkeletalMeshComponent* SniperGun;
	
public:
    // �Ѿ� ����
    UPROPERTY(EditAnywhere, Category = BulletFactory)
    TSubclassOf<class ABullet> BulletFactory;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Fire;

    // �Ѿ� �߻� ó��
    void InputFire(const struct FInputActionValue& inputValue);

    // ī�޶� ����ũ �������Ʈ�� ������ ����
    UPROPERTY(EditDefaultsOnly, Category = CameraMotion)
    TSubclassOf<class UCameraShakeBase> CameraShake;

    // �Ѿ� �߻� ����
    UPROPERTY(EditDefaultsOnly, Category = Sound)
    class USoundBase* BulletSound;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_HandGun;
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_SniperGun;

    // ����(Hand Gun)�� ��� ������ Ȯ��
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = TPS)
    bool bUsingHandGun = true;
    // ����(Sinper Gun)�� ��� ������ Ȯ��
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = TPS)
    bool bUsingSniperGun = true;
    // ����(Hand Gun)���� ����
    void ChangeToHandGun(const struct FInputActionValue& inputValue);
    // ����(Sniper Gun)���� ����
    void ChangeToSniperGun(const struct FInputActionValue& inputValue);

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    class UInputAction* IA_Sniper;
    // �������� ���� ó�� 
    void SniperAim(const struct FInputActionValue& inputValue);
    // �������� ���� ������ ����
    bool bSniperAim = false;


    // ũ�ν����, �������� ���� UI ������ ������ �ִ�.
    UPROPERTY(EditDefaultsOnly, Category = CrosshairUI)
    TSubclassOf<class UUserWidget> CrosshairUIfactory;

    UPROPERTY(EditDefaultsOnly)
    class UUserWidget* CrosshairUI;

    UPROPERTY(EditDefaultsOnly, Category = SniperUI)
    TSubclassOf<class UUserWidget> SniperUIfactory;

    UPROPERTY(EditDefaultsOnly)
    class UUserWidget* SniperUI;

    // �Ѿ� ���� ȿ�� ����
    UPROPERTY(EditAnywhere, Category = BulletEffect)
    class UParticleSystem* BulletEffectFactory;
};
