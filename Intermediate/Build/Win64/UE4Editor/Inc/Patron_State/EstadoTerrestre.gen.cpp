// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/EstadoTerrestre.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstadoTerrestre() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstadoTerrestre_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstadoTerrestre();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
	PATRON_STATE_API UClass* Z_Construct_UClass_UEstado_NoRegister();
// End Cross Module References
	void AEstadoTerrestre::StaticRegisterNativesAEstadoTerrestre()
	{
	}
	UClass* Z_Construct_UClass_AEstadoTerrestre_NoRegister()
	{
		return AEstadoTerrestre::StaticClass();
	}
	struct Z_Construct_UClass_AEstadoTerrestre_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstadoTerrestre_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstadoTerrestre_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstadoTerrestre.h" },
		{ "ModuleRelativePath", "EstadoTerrestre.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstadoTerrestre_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UEstado_NoRegister, (int32)VTABLE_OFFSET(AEstadoTerrestre, IEstado), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstadoTerrestre_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstadoTerrestre>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstadoTerrestre_Statics::ClassParams = {
		&AEstadoTerrestre::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEstadoTerrestre_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstadoTerrestre_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstadoTerrestre()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstadoTerrestre_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstadoTerrestre, 76891515);
	template<> PATRON_STATE_API UClass* StaticClass<AEstadoTerrestre>()
	{
		return AEstadoTerrestre::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstadoTerrestre(Z_Construct_UClass_AEstadoTerrestre, &AEstadoTerrestre::StaticClass, TEXT("/Script/Patron_State"), TEXT("AEstadoTerrestre"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstadoTerrestre);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
