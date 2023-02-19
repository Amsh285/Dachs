#pragma once

#include "Core.h"

namespace Dachs
{
	class DACHS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// define in client
	Application* CreateApplication();
}

