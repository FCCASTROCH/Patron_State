// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/ProyectilE.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProyectilE() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_AProyectilE_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_AProyectilE();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void AProyectilE::StaticRegisterNativesAProyectilE()
	{
	}
	UClass* Z_Construct_UClass_AProyectilE_NoRegister()
	{
		return AProyectilE::StaticClass();
	}
	struct Z_Construct_UClass_AProyectilE_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProyectilE_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProyectilE_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProyectilE.h" },
		{ "ModuleRelativePath", "ProyectilE.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProyectilE_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProyectilE>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProyectilE_Statics::ClassParams = {
		&AProyectilE::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AProyectilE_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProyectilE_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProyectilE()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProyectilE_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProyectilE, 3085958978);
	template<> PATRON_STATE_API UClass* StaticClass<AProyectilE>()
	{
		return AProyectilE::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProyectilE(Z_Construct_UClass_AProyectilE, &AProyectilE::StaticClass, TEXT("/Script/Patron_State"), TEXT("AProyectilE"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProyectilE);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
