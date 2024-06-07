// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/NaveEspecial.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveEspecial() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveEspecial_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveEspecial();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void ANaveEspecial::StaticRegisterNativesANaveEspecial()
	{
	}
	UClass* Z_Construct_UClass_ANaveEspecial_NoRegister()
	{
		return ANaveEspecial::StaticClass();
	}
	struct Z_Construct_UClass_ANaveEspecial_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveEspecial_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveEspecial_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NaveEspecial.h" },
		{ "ModuleRelativePath", "NaveEspecial.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveEspecial_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveEspecial>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveEspecial_Statics::ClassParams = {
		&ANaveEspecial::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ANaveEspecial_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveEspecial_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveEspecial()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveEspecial_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveEspecial, 4237564252);
	template<> PATRON_STATE_API UClass* StaticClass<ANaveEspecial>()
	{
		return ANaveEspecial::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveEspecial(Z_Construct_UClass_ANaveEspecial, &ANaveEspecial::StaticClass, TEXT("/Script/Patron_State"), TEXT("ANaveEspecial"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveEspecial);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
