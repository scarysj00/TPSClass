// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTPS_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TPS;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TPS()
	{
		if (!Z_Registration_Info_UPackage__Script_TPS.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/TPS",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xB8306734,
				0x6EABE266,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TPS.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_TPS.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TPS(Z_Construct_UPackage__Script_TPS, TEXT("/Script/TPS"), Z_Registration_Info_UPackage__Script_TPS, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB8306734, 0x6EABE266));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
