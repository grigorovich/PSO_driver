// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ShaderPipelineCache.h"
#include "PSO_driverBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/


UCLASS()
class UPSO_driverBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	// ---------------------
	// atomic functions
	// ---------------------
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PSO Save PipelineFileCache", Keywords = "PSO_driver Save Pipeline File Cache", ToolTip="Saves the current shader pipeline cache to disk using one of the defined save modes, Fast uses an incremental approach whereas Slow will consolidate all data into the file."), Category = "PSO_driverTesting")
	static void PSO_SavePipelineFileCache();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PSO Get NumPrecompilesActive", Keywords = "PSO_driver NumPrecompilesActive", ToolTip="Returns the number of pipelines actively being precompiled this frame"), Category = "PSO_driverTesting")
	static int32 PSO_NumPrecompilesActive();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PSO Get NumPrecompilesRemaining", Keywords = "PSO_driver NumPrecompilesRemaining", ToolTip="Determine the total number of outstanding PSOs to compile and keep the loading screen or movie visible until complete."), Category = "PSO_driverTesting")
	static int32 NumPrecompilesRemaining();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PSO Set BatchMode", Keywords = "PSO_driver Set BatchMode", ToolTip="Sets the precompilation batching mode. 0 - Background, 1 - Fast, 2 - Precompile"), Category = "PSO_driverTesting")
	static void PSO_SetBatchMode(int32 Mode);

	// ---------------------
	// complex functions
	// ---------------------
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PSO Pause Compiling Cache", Keywords = "PSO_driver stop compiling", ToolTip="#wip Need fillup"), Category = "PSO_driverTesting")
	static void PSO_PauseCompilingCache();
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PSO Is Compiling", Keywords = "PSO_driver check", ToolTip="#wip Need fillup"), Category = "PSO_driverTesting")
	static bool PSO_IsCompiling(int32& number_of_ordered);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PSO Start Fast Compiling Cache", Keywords = "PSO_driver start compiling", ToolTip="#wip Need fillup"), Category = "PSO_driverTesting")
	static void PSO_StartFastCompilingCache();
	

};
