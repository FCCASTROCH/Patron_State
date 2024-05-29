// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/Escaner.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEscaner() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_AEscaner_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_AEscaner();
	PATRON_STATE_API UClass* Z_Construct_UClass_APublicador();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void AEscaner::StaticRegisterNativesAEscaner()
	{
	}
	UClass* Z_Construct_UClass_AEscaner_NoRegister()
	{
		return AEscaner::StaticClass();
	}
	struct Z_Construct_UClass_AEscaner_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEscaner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APublicador,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEscaner_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Escaner.h" },
		{ "ModuleRelativePath", "Escaner.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEscaner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEscaner>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEscaner_Statics::ClassParams = {
		&AEscaner::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEscaner_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEscaner_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEscaner()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEscaner_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEscaner, 759184622);
	template<> PATRON_STATE_API UClass* StaticClass<AEscaner>()
	{
		return AEscaner::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEscaner(Z_Construct_UClass_AEscaner, &AEscaner::StaticClass, TEXT("/Script/Patron_State"), TEXT("AEscaner"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEscaner);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
