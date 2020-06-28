// Copyright Epic Games, Inc. All Rights Reserved.

#include "PSO_driverBPLibrary.h"
#include "PSO_driver.h"
#include "ShaderPipelineCache.h"

UPSO_driverBPLibrary::UPSO_driverBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

/* --------------------------
   Atomic Functions
   --------------------------*/

void UPSO_driverBPLibrary::PSO_SavePipelineFileCache()
{
	FShaderPipelineCache::SavePipelineFileCache(FPipelineFileCache::SaveMode::Incremental);
}

int32 UPSO_driverBPLibrary::PSO_NumPrecompilesActive()
{
	return((int32) FShaderPipelineCache::NumPrecompilesActive());
}

int32 UPSO_driverBPLibrary::NumPrecompilesRemaining()
{
	return((int32) FShaderPipelineCache::NumPrecompilesRemaining());
}

void UPSO_driverBPLibrary::PSO_SetBatchMode(int32 Mode)
{
	switch( Mode )
	{
		case 0:
			FShaderPipelineCache::SetBatchMode(FShaderPipelineCache::BatchMode::Background);
			break;
		case 1:
			FShaderPipelineCache::SetBatchMode(FShaderPipelineCache::BatchMode::Fast);
			break;
		case 2:
			FShaderPipelineCache::SetBatchMode(FShaderPipelineCache::BatchMode::Precompile);
			break;
	}
}

/* --------------------------
   Complex Functions
   --------------------------*/

void UPSO_driverBPLibrary::PSO_PauseCompilingCache()
{
	FShaderPipelineCache::PauseBatching();
}

bool UPSO_driverBPLibrary::PSO_IsCompiling(int32& number_of_ordered)
{
	number_of_ordered=(int32) FShaderPipelineCache::NumPrecompilesRemaining();
	if (number_of_ordered>0) {
		return true;
	} else {
		return false;
	}
}

void UPSO_driverBPLibrary::PSO_StartFastCompilingCache()
{
	FShaderPipelineCache::SetBatchMode(FShaderPipelineCache::BatchMode::Fast);
	FShaderPipelineCache::ResumeBatching();
}
