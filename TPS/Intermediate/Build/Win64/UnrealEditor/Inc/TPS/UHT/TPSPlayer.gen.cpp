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
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATPSPlayer_Statics::NewProp_Direction_MetaData[] = {
		{ "Category", "TPS" },
		{ "ModuleRelativePath", "Public/TPSPlayer.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATPSPlayer_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATPSPlayer, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATPSPlayer_Statics::NewProp_Direction_MetaData), Z_Construct_UClass_ATPSPlayer_Statics::NewProp_Direction_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATPSPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_SpringArmComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_CameraComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATPSPlayer_Statics::NewProp_Direction,
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
		{ Z_Construct_UClass_ATPSPlayer, ATPSPlayer::StaticClass, TEXT("ATPSPlayer"), &Z_Registration_Info_UClass_ATPSPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATPSPlayer), 3819665696U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_1988497887(TEXT("/Script/TPS"),
		Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_TPSPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
