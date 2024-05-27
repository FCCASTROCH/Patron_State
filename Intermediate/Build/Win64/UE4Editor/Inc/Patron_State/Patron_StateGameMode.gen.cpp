// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/Patron_StateGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePatron_StateGameMode() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_APatron_StateGameMode_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_APatron_StateGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void APatron_StateGameMode::StaticRegisterNativesAPatron_StateGameMode()
	{
	}
	UClass* Z_Construct_UClass_APatron_StateGameMode_NoRegister()
	{
		return APatron_StateGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APatron_StateGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APatron_StateGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APatron_StateGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Patron_StateGameMode.h" },
		{ "ModuleRelativePath", "Patron_StateGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APatron_StateGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APatron_StateGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APatron_StateGameMode_Statics::ClassParams = {
		&APatron_StateGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_APatron_StateGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APatron_StateGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APatron_StateGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APatron_StateGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APatron_StateGameMode, 3185513450);
	template<> PATRON_STATE_API UClass* StaticClass<APatron_StateGameMode>()
	{
		return APatron_StateGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APatron_StateGameMode(Z_Construct_UClass_APatron_StateGameMode, &APatron_StateGameMode::StaticClass, TEXT("/Script/Patron_State"), TEXT("APatron_StateGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APatron_StateGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
