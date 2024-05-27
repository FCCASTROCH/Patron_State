// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/EstadoAereo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstadoAereo() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstadoAereo_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstadoAereo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
	PATRON_STATE_API UClass* Z_Construct_UClass_UEstado_NoRegister();
// End Cross Module References
	void AEstadoAereo::StaticRegisterNativesAEstadoAereo()
	{
	}
	UClass* Z_Construct_UClass_AEstadoAereo_NoRegister()
	{
		return AEstadoAereo::StaticClass();
	}
	struct Z_Construct_UClass_AEstadoAereo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstadoAereo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstadoAereo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstadoAereo.h" },
		{ "ModuleRelativePath", "EstadoAereo.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstadoAereo_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UEstado_NoRegister, (int32)VTABLE_OFFSET(AEstadoAereo, IEstado), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstadoAereo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstadoAereo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstadoAereo_Statics::ClassParams = {
		&AEstadoAereo::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstadoAereo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstadoAereo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstadoAereo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstadoAereo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstadoAereo, 837654916);
	template<> PATRON_STATE_API UClass* StaticClass<AEstadoAereo>()
	{
		return AEstadoAereo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstadoAereo(Z_Construct_UClass_AEstadoAereo, &AEstadoAereo::StaticClass, TEXT("/Script/Patron_State"), TEXT("AEstadoAereo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstadoAereo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
