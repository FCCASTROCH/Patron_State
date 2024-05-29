// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/NaveTerrestre.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveTerrestre() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestre_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_ANaveTerrestre();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
	PATRON_STATE_API UClass* Z_Construct_UClass_AEscaner_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_USubscriptor_NoRegister();
// End Cross Module References
	void ANaveTerrestre::StaticRegisterNativesANaveTerrestre()
	{
	}
	UClass* Z_Construct_UClass_ANaveTerrestre_NoRegister()
	{
		return ANaveTerrestre::StaticClass();
	}
	struct Z_Construct_UClass_ANaveTerrestre_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Escaner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Escaner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANaveTerrestre_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveTerrestre_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NaveTerrestre.h" },
		{ "ModuleRelativePath", "NaveTerrestre.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANaveTerrestre_Statics::NewProp_Escaner_MetaData[] = {
		{ "Category", "Subscriptor" },
		{ "ModuleRelativePath", "NaveTerrestre.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANaveTerrestre_Statics::NewProp_Escaner = { "Escaner", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ANaveTerrestre, Escaner), Z_Construct_UClass_AEscaner_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ANaveTerrestre_Statics::NewProp_Escaner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveTerrestre_Statics::NewProp_Escaner_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANaveTerrestre_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANaveTerrestre_Statics::NewProp_Escaner,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ANaveTerrestre_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_USubscriptor_NoRegister, (int32)VTABLE_OFFSET(ANaveTerrestre, ISubscriptor), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANaveTerrestre_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANaveTerrestre>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANaveTerrestre_Statics::ClassParams = {
		&ANaveTerrestre::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANaveTerrestre_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANaveTerrestre_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ANaveTerrestre_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANaveTerrestre_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANaveTerrestre()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANaveTerrestre_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANaveTerrestre, 2954977530);
	template<> PATRON_STATE_API UClass* StaticClass<ANaveTerrestre>()
	{
		return ANaveTerrestre::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANaveTerrestre(Z_Construct_UClass_ANaveTerrestre, &ANaveTerrestre::StaticClass, TEXT("/Script/Patron_State"), TEXT("ANaveTerrestre"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANaveTerrestre);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
