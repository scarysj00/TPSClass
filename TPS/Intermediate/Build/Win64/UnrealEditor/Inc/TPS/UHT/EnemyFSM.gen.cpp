// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TPS/Public/EnemyFSM.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyFSM() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_AAIController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	TPS_API UClass* Z_Construct_UClass_AEnemy_NoRegister();
	TPS_API UClass* Z_Construct_UClass_ATPSPlayer_NoRegister();
	TPS_API UClass* Z_Construct_UClass_UEnemyAnim_NoRegister();
	TPS_API UClass* Z_Construct_UClass_UEnemyFSM();
	TPS_API UClass* Z_Construct_UClass_UEnemyFSM_NoRegister();
	TPS_API UEnum* Z_Construct_UEnum_TPS_EEnemyState();
	UPackage* Z_Construct_UPackage__Script_TPS();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEnemyState;
	static UEnum* EEnemyState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EEnemyState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EEnemyState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_TPS_EEnemyState, (UObject*)Z_Construct_UPackage__Script_TPS(), TEXT("EEnemyState"));
		}
		return Z_Registration_Info_UEnum_EEnemyState.OuterSingleton;
	}
	template<> TPS_API UEnum* StaticEnum<EEnemyState>()
	{
		return EEnemyState_StaticEnum();
	}
	struct Z_Construct_UEnum_TPS_EEnemyState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_TPS_EEnemyState_Statics::Enumerators[] = {
		{ "EEnemyState::Idle", (int64)EEnemyState::Idle },
		{ "EEnemyState::Move", (int64)EEnemyState::Move },
		{ "EEnemyState::Attack", (int64)EEnemyState::Attack },
		{ "EEnemyState::Damage", (int64)EEnemyState::Damage },
		{ "EEnemyState::Die", (int64)EEnemyState::Die },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_TPS_EEnemyState_Statics::Enum_MetaDataParams[] = {
		{ "Attack.Name", "EEnemyState::Attack" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "Damage.Name", "EEnemyState::Damage" },
		{ "Die.Name", "EEnemyState::Die" },
		{ "Idle.Name", "EEnemyState::Idle" },
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
		{ "Move.Name", "EEnemyState::Move" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_TPS_EEnemyState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_TPS,
		nullptr,
		"EEnemyState",
		"EEnemyState",
		Z_Construct_UEnum_TPS_EEnemyState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_TPS_EEnemyState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_TPS_EEnemyState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_TPS_EEnemyState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_TPS_EEnemyState()
	{
		if (!Z_Registration_Info_UEnum_EEnemyState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEnemyState.InnerSingleton, Z_Construct_UEnum_TPS_EEnemyState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EEnemyState.InnerSingleton;
	}
	void UEnemyFSM::StaticRegisterNativesUEnemyFSM()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEnemyFSM);
	UClass* Z_Construct_UClass_UEnemyFSM_NoRegister()
	{
		return UEnemyFSM::StaticClass();
	}
	struct Z_Construct_UClass_UEnemyFSM_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_mState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_mState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IdleDelayTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_IdleDelayTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Me_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Me;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttackDelayTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AttackDelayTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HP_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_HP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamageDelayTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageDelayTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DieSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DieSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Anim_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Anim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AI_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AI;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEnemyFSM_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_TPS,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "EnemyFSM.h" },
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_mState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_mState_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_mState = { "mState", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, mState), Z_Construct_UEnum_TPS_EEnemyState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_mState_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_mState_MetaData) }; // 1078518965
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_IdleDelayTime_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_IdleDelayTime = { "IdleDelayTime", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, IdleDelayTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_IdleDelayTime_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_IdleDelayTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Target_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, Target), Z_Construct_UClass_ATPSPlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Target_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Target_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Me_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Me = { "Me", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, Me), Z_Construct_UClass_AEnemy_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Me_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Me_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackRange_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackRange_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackRange_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackDelayTime_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackDelayTime = { "AttackDelayTime", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, AttackDelayTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackDelayTime_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackDelayTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_HP_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xc3\xbc\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_HP = { "HP", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, HP), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_HP_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_HP_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DamageDelayTime_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DamageDelayTime = { "DamageDelayTime", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, DamageDelayTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DamageDelayTime_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DamageDelayTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DieSpeed_MetaData[] = {
		{ "Category", "FSM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xc6\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc6\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DieSpeed = { "DieSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, DieSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DieSpeed_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DieSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Anim_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xcf\xb8\xef\xbf\xbd\xef\xbf\xbd\xcc\xbc\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Anim = { "Anim", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, Anim), Z_Construct_UClass_UEnemyAnim_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Anim_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Anim_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AI_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Enemy\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd AIController\n" },
#endif
		{ "ModuleRelativePath", "Public/EnemyFSM.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enemy\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd AIController" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AI = { "AI", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyFSM, AI), Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AI_MetaData), Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AI_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyFSM_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_mState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_mState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_IdleDelayTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Me,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackRange,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AttackDelayTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_HP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DamageDelayTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_DieSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_Anim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyFSM_Statics::NewProp_AI,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEnemyFSM_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyFSM>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEnemyFSM_Statics::ClassParams = {
		&UEnemyFSM::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UEnemyFSM_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::Class_MetaDataParams), Z_Construct_UClass_UEnemyFSM_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyFSM_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UEnemyFSM()
	{
		if (!Z_Registration_Info_UClass_UEnemyFSM.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEnemyFSM.OuterSingleton, Z_Construct_UClass_UEnemyFSM_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEnemyFSM.OuterSingleton;
	}
	template<> TPS_API UClass* StaticClass<UEnemyFSM>()
	{
		return UEnemyFSM::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyFSM);
	UEnemyFSM::~UEnemyFSM() {}
	struct Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_Statics::EnumInfo[] = {
		{ EEnemyState_StaticEnum, TEXT("EEnemyState"), &Z_Registration_Info_UEnum_EEnemyState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1078518965U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyFSM, UEnemyFSM::StaticClass, TEXT("UEnemyFSM"), &Z_Registration_Info_UClass_UEnemyFSM, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyFSM), 2355561112U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_1558688516(TEXT("/Script/TPS"),
		Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TPS_Source_TPS_Public_EnemyFSM_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
