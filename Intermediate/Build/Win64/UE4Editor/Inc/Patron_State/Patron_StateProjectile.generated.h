// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef PATRON_STATE_Patron_StateProjectile_generated_h
#error "Patron_StateProjectile.generated.h already included, missing '#pragma once' in Patron_StateProjectile.h"
#endif
#define PATRON_STATE_Patron_StateProjectile_generated_h

#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_SPARSE_DATA
#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPatron_StateProjectile(); \
	friend struct Z_Construct_UClass_APatron_StateProjectile_Statics; \
public: \
	DECLARE_CLASS(APatron_StateProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Patron_State"), NO_API) \
	DECLARE_SERIALIZER(APatron_StateProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPatron_StateProjectile(); \
	friend struct Z_Construct_UClass_APatron_StateProjectile_Statics; \
public: \
	DECLARE_CLASS(APatron_StateProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Patron_State"), NO_API) \
	DECLARE_SERIALIZER(APatron_StateProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APatron_StateProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APatron_StateProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APatron_StateProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APatron_StateProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APatron_StateProjectile(APatron_StateProjectile&&); \
	NO_API APatron_StateProjectile(const APatron_StateProjectile&); \
public:


#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APatron_StateProjectile(APatron_StateProjectile&&); \
	NO_API APatron_StateProjectile(const APatron_StateProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APatron_StateProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APatron_StateProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APatron_StateProjectile)


#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(APatron_StateProjectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(APatron_StateProjectile, ProjectileMovement); }


#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_12_PROLOG
#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_SPARSE_DATA \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_RPC_WRAPPERS \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_INCLASS \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_SPARSE_DATA \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_INCLASS_NO_PURE_DECLS \
	Patron_State_Source_Patron_State_Patron_StateProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PATRON_STATE_API UClass* StaticClass<class APatron_StateProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Patron_State_Source_Patron_State_Patron_StateProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS