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
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Projectil_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Projectil_Mesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Projectil_Movement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Projectil_Movement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Projectil_Collision_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Projectil_Collision;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Mesh_MetaData[] = {
		{ "Category", "Projectile" },
		{ "Comment", "//Componente de Malla para el proyectil\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProyectilE.h" },
		{ "ToolTip", "Componente de Malla para el proyectil" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Mesh = { "Projectil_Mesh", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProyectilE, Projectil_Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Mesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Movement_MetaData[] = {
		{ "Category", "Projectile" },
		{ "Comment", "//Componente de Movimiento para el proyectil\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProyectilE.h" },
		{ "ToolTip", "Componente de Movimiento para el proyectil" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Movement = { "Projectil_Movement", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProyectilE, Projectil_Movement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Movement_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Movement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Collision_MetaData[] = {
		{ "Category", "Projectile" },
		{ "Comment", "//Componente de colision para el proyectil\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ProyectilE.h" },
		{ "ToolTip", "Componente de colision para el proyectil" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Collision = { "Projectil_Collision", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AProyectilE, Projectil_Collision), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Collision_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Collision_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AProyectilE_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Movement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AProyectilE_Statics::NewProp_Projectil_Collision,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProyectilE_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProyectilE>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProyectilE_Statics::ClassParams = {
		&AProyectilE::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AProyectilE_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AProyectilE_Statics::PropPointers),
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
	IMPLEMENT_CLASS(AProyectilE, 2908376499);
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
