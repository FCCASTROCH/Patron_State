// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/NaveTerrestreModificado.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveTerrestreModificado() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestreModificado_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestreModificado();
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestre();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void ANaveTerrestreModificado::StaticRegisterNativesANaveTerrestreModificado()
	{
	}
	UClass* Z_Construct_UClass_ANaveTerrestreModificado_NoRegister()
	{
		return ANaveTerrestreModificado::StaticClass();
	}
	struct Z_Construct_UClass_ANaveTerrestreModificado_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveTerrestreModificado_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveTerrestre,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveTerrestreModificado_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "NaveTerrestreModificado.h" },
		{ "ModuleRelativePath", "NaveTerrestreModificado.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveTerrestreModificado_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveTerrestreModificado>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveTerrestreModificado_Statics::ClassParams = {
		&ANaveTerrestreModificado::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ANaveTerrestreModificado_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveTerrestreModificado_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveTerrestreModificado()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveTerrestreModificado_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveTerrestreModificado, 1778562743);
	template<> PATRON_STATE_API UClass* StaticClass<ANaveTerrestreModificado>()
	{
		return ANaveTerrestreModificado::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveTerrestreModificado(Z_Construct_UClass_ANaveTerrestreModificado, &ANaveTerrestreModificado::StaticClass, TEXT("/Script/Patron_State"), TEXT("ANaveTerrestreModificado"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveTerrestreModificado);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
