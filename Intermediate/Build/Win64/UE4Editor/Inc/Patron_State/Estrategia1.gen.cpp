// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/Estrategia1.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategia1() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstrategia1_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstrategia1();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void AEstrategia1::StaticRegisterNativesAEstrategia1()
	{
	}
	UClass* Z_Construct_UClass_AEstrategia1_NoRegister()
	{
		return AEstrategia1::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategia1_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategia1_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategia1_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Estrategia1.h" },
		{ "ModuleRelativePath", "Estrategia1.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategia1_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategia1>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategia1_Statics::ClassParams = {
		&AEstrategia1::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEstrategia1_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategia1_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategia1()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategia1_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategia1, 2190697253);
	template<> PATRON_STATE_API UClass* StaticClass<AEstrategia1>()
	{
		return AEstrategia1::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategia1(Z_Construct_UClass_AEstrategia1, &AEstrategia1::StaticClass, TEXT("/Script/Patron_State"), TEXT("AEstrategia1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategia1);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
