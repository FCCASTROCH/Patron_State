// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/NaveTerrestreEspecial.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveTerrestreEspecial() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestreEspecial_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestreEspecial();
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestre();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void ANaveTerrestreEspecial::StaticRegisterNativesANaveTerrestreEspecial()
	{
	}
	UClass* Z_Construct_UClass_ANaveTerrestreEspecial_NoRegister()
	{
		return ANaveTerrestreEspecial::StaticClass();
	}
	struct Z_Construct_UClass_ANaveTerrestreEspecial_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveTerrestreEspecial_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANaveTerrestre,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveTerrestreEspecial_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "NaveTerrestreEspecial.h" },
		{ "ModuleRelativePath", "NaveTerrestreEspecial.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveTerrestreEspecial_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveTerrestreEspecial>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveTerrestreEspecial_Statics::ClassParams = {
		&ANaveTerrestreEspecial::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ANaveTerrestreEspecial_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveTerrestreEspecial_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveTerrestreEspecial()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveTerrestreEspecial_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveTerrestreEspecial, 2202741380);
	template<> PATRON_STATE_API UClass* StaticClass<ANaveTerrestreEspecial>()
	{
		return ANaveTerrestreEspecial::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveTerrestreEspecial(Z_Construct_UClass_ANaveTerrestreEspecial, &ANaveTerrestreEspecial::StaticClass, TEXT("/Script/Patron_State"), TEXT("ANaveTerrestreEspecial"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveTerrestreEspecial);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
