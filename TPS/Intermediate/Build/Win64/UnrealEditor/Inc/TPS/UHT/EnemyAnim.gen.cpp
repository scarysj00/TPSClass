// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TPS/Public/EnemyAnim.h"
#include "../../Source/Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyAnim() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	TPS_API UClass* Z_Construct_UClass_UEnemyAnim();
	TPS_API UClass* Z_Construct_UClass_UEnemyAnim_NoRegister();
	TPS_API UEnum* Z_Construct_UEnum_TPS_EEnemyState();
	UPackage* Z_Construct_UPackage__Script_TPS();
// End Cross Module References
	DEFINE_FUNCTION(UEnemyAnim::execOnDamageEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDamageEnd();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UEnemyAnim::execOnEndAttackAnimation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnEndAttackAnimation();
		P_NATIVE_END;
	}
	struct EnemyAnim_eventPlayDamageAnim_Parms
	{
		FName SectionName;
	};
	static FName NAME_UEnemyAnim_PlayDamageAnim = FName(TEXT("PlayDamageAnim"));
	void UEnemyAnim::PlayDamageAnim(FName SectionName)
	{
		EnemyAnim_eventPlayDamageAnim_Parms Parms;
		Parms.SectionName=SectionName;
		ProcessEvent(FindFunctionChecked(NAME_UEnemyAnim_PlayDamageAnim),&Parms);
	}
	void UEnemyAnim::StaticRegisterNativesUEnemyAnim()
	{
		UClass* Class = UEnemyAnim::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnDamageEnd", &UEnemyAnim::execOnDamageEnd },
			{ "OnEndAttackAnimation", &UEnemyAnim::execOnEndAttackAnimation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UEnemyAnim_OnDamageEnd_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnim_OnDamageEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/EnemyAnim.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnim_OnDamageEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnim, nullptr, "OnDamageEnd", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_OnDamageEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEnemyAnim_OnDamageEnd_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UEnemyAnim_OnDamageEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEnemyAnim_OnDamageEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "FSMEvent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyAnim.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnim, nullptr, "OnEndAttackAnimation", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics
	{
		static const UECodeGen_Private::FNamePropertyParams NewProp_SectionName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::NewProp_SectionName = { "SectionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EnemyAnim_eventPlayDamageAnim_Parms, SectionName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::NewProp_SectionName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::Function_MetaDataParams[] = {
		{ "Category", "FSMEvent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyAnim.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UEnemyAnim, nullptr, "PlayDamageAnim", nullptr, nullptr, Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::PropPointers), sizeof(EnemyAnim_eventPlayDamageAnim_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::PropPointers) < 2048);
	static_assert(sizeof(EnemyAnim_eventPlayDamageAnim_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEnemyAnim);
	UClass* Z_Construct_UClass_UEnemyAnim_NoRegister()
	{
		return UEnemyAnim::StaticClass();
	}
	struct Z_Construct_UClass_UEnemyAnim_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_AnimState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_AnimState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAttackPlay_MetaData[];
#endif
		static void NewProp_bAttackPlay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttackPlay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDieDone_MetaData[];
#endif
		static void NewProp_bDieDone_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDieDone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEnemyAnim_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_TPS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UEnemyAnim_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UEnemyAnim_OnDamageEnd, "OnDamageEnd" }, // 2896440077
		{ &Z_Construct_UFunction_UEnemyAnim_OnEndAttackAnimation, "OnEndAttackAnimation" }, // 2112299715
		{ &Z_Construct_UFunction_UEnemyAnim_PlayDamageAnim, "PlayDamageAnim" }, // 1231640863
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "EnemyAnim.h" },
		{ "ModuleRelativePath", "Public/EnemyAnim.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_AnimState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::NewProp_AnimState_MetaData[] = {
		{ "Category", "FSM" },
		{ "ModuleRelativePath", "Public/EnemyAnim.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_AnimState = { "AnimState", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyAnim, AnimState), Z_Construct_UEnum_TPS_EEnemyState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_AnimState_MetaData), Z_Construct_UClass_UEnemyAnim_Statics::NewProp_AnimState_MetaData) }; // 1078518965
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyAnim.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	void Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_SetBit(void* Obj)
	{
		((UEnemyAnim*)Obj)->bAttackPlay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay = { "bAttackPlay", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEnemyAnim), &Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_MetaData), Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyAnim.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	void Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_SetBit(void* Obj)
	{
		((UEnemyAnim*)Obj)->bDieDone = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone = { "bDieDone", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEnemyAnim), &Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_MetaData), Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyAnim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_AnimState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_AnimState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bAttackPlay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyAnim_Statics::NewProp_bDieDone,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEnemyAnim_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyAnim>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEnemyAnim_Statics::ClassParams = {
		&UEnemyAnim::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UEnemyAnim_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::Class_MetaDataParams), Z_Construct_UClass_UEnemyAnim_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyAnim_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UEnemyAnim()
	{
		if (!Z_Registration_Info_UClass_UEnemyAnim.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEnemyAnim.OuterSingleton, Z_Construct_UClass_UEnemyAnim_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEnemyAnim.OuterSingleton;
	}
	template<> TPS_API UClass* StaticClass<UEnemyAnim>()
	{
		return UEnemyAnim::StaticClass();
	}
	UEnemyAnim::UEnemyAnim(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyAnim);
	UEnemyAnim::~UEnemyAnim() {}
	struct Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyAnim_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyAnim_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyAnim, UEnemyAnim::StaticClass, TEXT("UEnemyAnim"), &Z_Registration_Info_UClass_UEnemyAnim, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyAnim), 3700985287U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyAnim_h_4136784800(TEXT("/Script/TPS"),
		Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyAnim_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyAnim_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
