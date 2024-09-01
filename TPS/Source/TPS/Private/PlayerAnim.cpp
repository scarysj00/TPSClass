// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "TPSPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	// 오너를 가져와서 유효성 체크를 하고 싶다.
	if (nullptr == Player)
	{
		auto Owner = TryGetPawnOwner();
		Player = Cast<ATPSPlayer>(Owner);
	}
	if (nullptr == Player)
	{
		return; // 책에 없는 부분
	}
	// 오너한테 Actor Forward Vector 와 Velocity 를 알아내 
	FVector Forward = Player->GetActorForwardVector();
	FVector Velocity = Player->GetVelocity();
	// Speed 의 값을 채우고 싶다.
	Speed = FVector::DotProduct(Forward, Velocity);
	// Actor Right Vector 를 알아내 
	FVector Right = Player->GetActorRightVector();
	// Direction 값을 채우고 싶다.
	Direction = FVector::DotProduct(Right, Velocity);
	// 오너를 ATPSPlayer로 캐스팅은 위에서 했다.
	// 캐릭터 무브먼트에서 Is Falling 을 가져와서 IsInAir 를 채우고 싶다.
	UCharacterMovementComponent* Movement = Player->GetCharacterMovement();
	IsInAir = Movement->IsFalling();
}
