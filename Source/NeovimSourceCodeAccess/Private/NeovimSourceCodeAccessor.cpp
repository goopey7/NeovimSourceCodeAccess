#include "NeovimSourceCodeAccessor.h"
#include "Internationalization/Internationalization.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"

#define LOCTEXT_NAMESPACE "NeovimSourceCodeAccessor"
bool FNeovimSourceCodeAccessor::CanAccessSourceCode() const
{
	// assume there is a bundled toolchain for installed builds and for source a toolchain should be around
	return true;
}

FName FNeovimSourceCodeAccessor::GetFName() const
{
	return FName("NeovimSourceCodeAccessor");
}

FText FNeovimSourceCodeAccessor::GetNameText() const 
{
	return LOCTEXT("NeovimDisplayName", "Neovim Source Code Access");
}

FText FNeovimSourceCodeAccessor::GetDescriptionText() const
{
	return LOCTEXT("NeovimDisplayDesc", "Open source code files in Neovim");
}

bool FNeovimSourceCodeAccessor::OpenSolution()
{
	return true;
}

bool FNeovimSourceCodeAccessor::OpenSolutionAtPath(const FString& InSolutionPath)
{
	FString Path = FPaths::GetPath(InSolutionPath);
	FPlatformProcess::ExploreFolder(*Path);

	return true;
}

bool FNeovimSourceCodeAccessor::DoesSolutionExist() const
{
	return false;
}

bool FNeovimSourceCodeAccessor::OpenFileAtLine(const FString& FullPath, int32 LineNumber, int32 ColumnNumber)
{
	return false;
}

bool FNeovimSourceCodeAccessor::OpenSourceFiles(const TArray<FString>& AbsoluteSourcePaths) 
{
	return false;
}

bool FNeovimSourceCodeAccessor::AddSourceFiles(const TArray<FString>& AbsoluteSourcePaths, const TArray<FString>& AvailableModules)
{
	return false;
}

bool FNeovimSourceCodeAccessor::SaveAllOpenDocuments() const
{
	return false;
}

void FNeovimSourceCodeAccessor::Tick(const float DeltaTime) 
{

}

#undef LOCTEXT_NAMESPACE
