// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/Estrategia2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategia2() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstrategia2_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_AEstrategia2();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
	PATRON_STATE_API UClass* Z_Construct_UClass_UIStrategy_NoRegister();
// End Cross Module References
	void AEstrategia2::StaticRegisterNativesAEstrategia2()
	{
	}
	UClass* Z_Construct_UClass_AEstrategia2_NoRegister()
	{
		return AEstrategia2::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategia2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategia2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategia2_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Estrategia2.h" },
		{ "ModuleRelativePath", "Estrategia2.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategia2_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIStrategy_NoRegister, (int32)VTABLE_OFFSET(AEstrategia2, IIStrategy), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategia2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategia2>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategia2_Statics::ClassParams = {
		&AEstrategia2::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstrategia2_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategia2_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategia2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategia2_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategia2, 2915419020);
	template<> PATRON_STATE_API UClass* StaticClass<AEstrategia2>()
	{
		return AEstrategia2::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategia2(Z_Construct_UClass_AEstrategia2, &AEstrategia2::StaticClass, TEXT("/Script/Patron_State"), TEXT("AEstrategia2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategia2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
