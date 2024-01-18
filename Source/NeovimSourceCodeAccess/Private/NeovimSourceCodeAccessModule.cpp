#include "NeovimSourceCodeAccessModule.h"
#include "Modules/ModuleManager.h"
#include "Features/IModularFeatures.h"

IMPLEMENT_MODULE( FNeovimSourceCodeAccessModule, NeovimSourceCodeAccess );

void FNeovimSourceCodeAccessModule::StartupModule()
{
	// Bind our source control provider to the editor
	IModularFeatures::Get().RegisterModularFeature(TEXT("SourceCodeAccessor"), &NeovimSourceCodeAccessor );
}

void FNeovimSourceCodeAccessModule::ShutdownModule()
{
	// unbind provider from editor
	IModularFeatures::Get().UnregisterModularFeature(TEXT("SourceCodeAccessor"), &NeovimSourceCodeAccessor);
}

FNeovimSourceCodeAccessor& FNeovimSourceCodeAccessModule::GetAccessor()
{
	return NeovimSourceCodeAccessor;
}
