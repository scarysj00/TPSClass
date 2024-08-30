// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlayerAnim.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TPS_PlayerAnim_generated_h
#error "PlayerAnim.generated.h already included, missing '#pragma once' in PlayerAnim.h"
#endif
#define TPS_PlayerAnim_generated_h

#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_SPARSE_DATA
#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_ACCESSORS
#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlayerAnim(); \
	friend struct Z_Construct_UClass_UPlayerAnim_Statics; \
public: \
	DECLARE_CLASS(UPlayerAnim, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TPS"), NO_API) \
	DECLARE_SERIALIZER(UPlayerAnim)


#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlayerAnim(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPlayerAnim(UPlayerAnim&&); \
	NO_API UPlayerAnim(const UPlayerAnim&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlayerAnim); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlayerAnim); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlayerAnim) \
	NO_API virtual ~UPlayerAnim();


#define FID_TPS_Source_TPS_Public_PlayerAnim_h_12_PROLOG
#define FID_TPS_Source_TPS_Public_PlayerAnim_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TPS_Source_TPS_Public_PlayerAnim_h_15_SPARSE_DATA \
	FID_TPS_Source_TPS_Public_PlayerAnim_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_TPS_Source_TPS_Public_PlayerAnim_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_TPS_Source_TPS_Public_PlayerAnim_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TPS_Source_TPS_Public_PlayerAnim_h_15_ACCESSORS \
	FID_TPS_Source_TPS_Public_PlayerAnim_h_15_INCLASS_NO_PURE_DECLS \
	FID_TPS_Source_TPS_Public_PlayerAnim_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TPS_API UClass* StaticClass<class UPlayerAnim>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TPS_Source_TPS_Public_PlayerAnim_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
