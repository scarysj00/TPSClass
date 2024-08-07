// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TPS/Public/TPSPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTPSPlayer() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	TPS_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	TPS_API UClass* Z_Construct_UClass_ATPSPlayer();
	TPS_API UClass* Z_Construct_UClass_ATPSPlayer_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TPS();
// End Cross Module References
	void ATPSPlayer::StaticRegisterNativesATPSPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATPSPlayer);
	UClass* Z_Construct_UClass_ATPSPlayer_NoRegister()
	{
		return ATPSPlayer::StaticClass();
	}
	struct Z_Construct_UClass_ATPSPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringArmComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HandGun_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HandGun;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SniperGun_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SniperGun;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BulletFactory_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_BulletFactory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IMC_TPS_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IMC_TPS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IA_LookUp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_LookUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IA_Turn_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Turn;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IA_Move_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Move;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IA_Jump_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Jump;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IA_Fire_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Fire;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IA_HandGun_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_HandGun;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IA_SniperGun_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_SniperGun;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATPSPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_TPS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TPSPlayer.h" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SpringArmComp_MetaData[] = {
		{ "Category", "TPSPlayer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 - Spring Arm, Camera\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 - Spring Arm, Camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SpringArmComp = { "SpringArmComp", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, SpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SpringArmComp_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SpringArmComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_CameraComp_MetaData[] = {
		{ "Category", "TPSPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_CameraComp = { "CameraComp", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, CameraComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_CameraComp_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_CameraComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_HandGun_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 - Weapon (\xea\xb6\x8c\xec\xb4\x9d)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 - Weapon (\xea\xb6\x8c\xec\xb4\x9d)" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_HandGun = { "HandGun", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, HandGun), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_HandGun_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_HandGun_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SniperGun_MetaData[] = {
		{ "Category", "Weapon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 - Weapon (\xec\x86\x8c\xec\xb4\x9d)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 - Weapon (\xec\x86\x8c\xec\xb4\x9d)" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SniperGun = { "SniperGun", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, SniperGun), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SniperGun_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SniperGun_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_BulletFactory_MetaData[] = {
		{ "Category", "BulletFactory" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_BulletFactory = { "BulletFactory", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, BulletFactory), Z_Construct_UClass_UClass, Z_Construct_UClass_ABullet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_BulletFactory_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_BulletFactory_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IMC_TPS_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9e\x85\xeb\xa0\xa5 \xec\xb2\x98\xeb\xa6\xac \xed\x95\xa8\xec\x88\x98 \xec\xa0\x9c\xec\x9e\x91\n" },
#endif
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x85\xeb\xa0\xa5 \xec\xb2\x98\xeb\xa6\xac \xed\x95\xa8\xec\x88\x98 \xec\xa0\x9c\xec\x9e\x91" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IMC_TPS = { "IMC_TPS", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IMC_TPS), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IMC_TPS_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IMC_TPS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_LookUp_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_LookUp = { "IA_LookUp", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IA_LookUp), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_LookUp_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_LookUp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Turn_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Turn = { "IA_Turn", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IA_Turn), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Turn_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Turn_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Move_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Move = { "IA_Move", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IA_Move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Move_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Move_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "PlayerSetting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb4\xeb\x8f\x99 \xec\x86\x8d\xeb\x8f\x84\n" },
#endif
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb4\xeb\x8f\x99 \xec\x86\x8d\xeb\x8f\x84" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_WalkSpeed_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_WalkSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Jump_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Jump = { "IA_Jump", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IA_Jump), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Jump_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Jump_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Fire_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Fire = { "IA_Fire", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IA_Fire), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Fire_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Fire_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_HandGun_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_HandGun = { "IA_HandGun", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IA_HandGun), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_HandGun_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_HandGun_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_SniperGun_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_SniperGun = { "IA_SniperGun", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, IA_SniperGun), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_SniperGun_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_SniperGun_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATPSPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SpringArmComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_CameraComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_HandGun,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SniperGun,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_BulletFactory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IMC_TPS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_LookUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Turn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Move,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_WalkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Jump,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_Fire,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_HandGun,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_IA_SniperGun,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATPSPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATPSPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATPSPlayer_Statics::ClassParams = {
		&ATPSPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATPSPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_ATPSPlayer_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATPSPlayer()
	{
		if (!Z_Registration_Info_UClass_ATPSPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATPSPlayer.OuterSingleton, Z_Construct_UClass_ATPSPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATPSPlayer.OuterSingleton;
	}
	template<> TPS_API UClass* StaticClass<ATPSPlayer>()
	{
		return ATPSPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATPSPlayer);
	ATPSPlayer::~ATPSPlayer() {}
	struct Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATPSPlayer, ATPSPlayer::StaticClass, TEXT("ATPSPlayer"), &Z_Registration_Info_UClass_ATPSPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATPSPlayer), 1337561070U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_3549033329(TEXT("/Script/TPS"),
		Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
