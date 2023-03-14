#include "dspch.h"
#include "Application.h"

namespace Dachs
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		DS_CORE_TRACE(e.ToString());

		while (true);
	}
}
