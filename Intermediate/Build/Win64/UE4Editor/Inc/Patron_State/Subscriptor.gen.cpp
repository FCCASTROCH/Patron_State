// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Patron_State/Subscriptor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSubscriptor() {}
// Cross Module References
	PATRON_STATE_API UClass* Z_Construct_UClass_USubscriptor_NoRegister();
	PATRON_STATE_API UClass* Z_Construct_UClass_USubscriptor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_Patron_State();
// End Cross Module References
	void USubscriptor::StaticRegisterNativesUSubscriptor()
	{
	}
	UClass* Z_Construct_UClass_USubscriptor_NoRegister()
	{
		return USubscriptor::StaticClass();
	}
	struct Z_Construct_UClass_USubscriptor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USubscriptor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_Patron_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USubscriptor_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subscriptor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USubscriptor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISubscriptor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USubscriptor_Statics::ClassParams = {
		&USubscriptor::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_USubscriptor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USubscriptor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USubscriptor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USubscriptor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USubscriptor, 1307229509);
	template<> PATRON_STATE_API UClass* StaticClass<USubscriptor>()
	{
		return USubscriptor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USubscriptor(Z_Construct_UClass_USubscriptor, &USubscriptor::StaticClass, TEXT("/Script/Patron_State"), TEXT("USubscriptor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USubscriptor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif