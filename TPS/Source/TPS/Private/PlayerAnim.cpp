// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "TPSPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	// ���ʸ� �����ͼ� ��ȿ�� üũ�� �ϰ� �ʹ�.
	if (nullptr == Player)
	{
		auto Owner = TryGetPawnOwner();
		Player = Cast<ATPSPlayer>(Owner);
	}
	if (nullptr == Player)
	{
		return; // å�� ���� �κ�
	}
	// �������� Actor Forward Vector �� Velocity �� �˾Ƴ� 
	FVector Forward = Player->GetActorForwardVector();
	FVector Velocity = Player->GetVelocity();
	// Speed �� ���� ä��� �ʹ�.
	Speed = FVector::DotProduct(Forward, Velocity);
	// Actor Right Vector �� �˾Ƴ� 
	FVector Right = Player->GetActorRightVector();
	// Direction ���� ä��� �ʹ�.
	Direction = FVector::DotProduct(Right, Velocity);
	// ���ʸ� ATPSPlayer�� ĳ������ ������ �ߴ�.
	// ĳ���� �����Ʈ���� Is Falling �� �����ͼ� IsInAir �� ä��� �ʹ�.
	UCharacterMovementComponent* Movement = Player->GetCharacterMovement();
	IsInAir = Movement->IsFalling();
}

void UPlayerAnim::PlayAttackAnim()
{
	Montage_Play(AttackAnimMontage);
}
