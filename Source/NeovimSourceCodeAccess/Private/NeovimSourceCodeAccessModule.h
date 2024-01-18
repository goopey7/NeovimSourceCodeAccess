#pragma once

#include "Modules/ModuleInterface.h"
#include "NeovimSourceCodeAccessor.h"

class FNeovimSourceCodeAccessModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	FNeovimSourceCodeAccessor& GetAccessor();

private:
	FNeovimSourceCodeAccessor NeovimSourceCodeAccessor;
};
