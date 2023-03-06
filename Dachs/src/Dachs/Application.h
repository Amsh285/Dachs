#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

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

