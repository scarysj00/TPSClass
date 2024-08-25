// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EnemyFSM.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TPS_EnemyFSM_generated_h
#error "EnemyFSM.generated.h already included, missing '#pragma once' in EnemyFSM.h"
#endif
#define TPS_EnemyFSM_generated_h

#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_SPARSE_DATA
#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_ACCESSORS
#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEnemyFSM(); \
	friend struct Z_Construct_UClass_UEnemyFSM_Statics; \
public: \
	DECLARE_CLASS(UEnemyFSM, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TPS"), NO_API) \
	DECLARE_SERIALIZER(UEnemyFSM)


#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEnemyFSM(UEnemyFSM&&); \
	NO_API UEnemyFSM(const UEnemyFSM&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEnemyFSM); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEnemyFSM); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEnemyFSM) \
	NO_API virtual ~UEnemyFSM();


#define FID_TPS_Source_TPS_Public_EnemyFSM_h_20_PROLOG
#define FID_TPS_Source_TPS_Public_EnemyFSM_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TPS_Source_TPS_Public_EnemyFSM_h_23_SPARSE_DATA \
	FID_TPS_Source_TPS_Public_EnemyFSM_h_23_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_TPS_Source_TPS_Public_EnemyFSM_h_23_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_TPS_Source_TPS_Public_EnemyFSM_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TPS_Source_TPS_Public_EnemyFSM_h_23_ACCESSORS \
	FID_TPS_Source_TPS_Public_EnemyFSM_h_23_INCLASS_NO_PURE_DECLS \
	FID_TPS_Source_TPS_Public_EnemyFSM_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TPS_API UClass* StaticClass<class UEnemyFSM>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TPS_Source_TPS_Public_EnemyFSM_h


#define FOREACH_ENUM_EENEMYSTATE(op) \
	op(EEnemyState::Idle) \
	op(EEnemyState::Move) \
	op(EEnemyState::Attack) \
	op(EEnemyState::Damage) \
	op(EEnemyState::Die) 

enum class EEnemyState : uint8;
template<> struct TIsUEnumClass<EEnemyState> { enum { Value = true }; };
template<> TPS_API UEnum* StaticEnum<EEnemyState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
