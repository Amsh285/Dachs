#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Dachs
{
	class DACHS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_window;
		bool m_Running = true;
	};

	// define in client
	Application* CreateApplication();
}

