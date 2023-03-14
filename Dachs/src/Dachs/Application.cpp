#include "dspch.h"
#include "Application.h"

namespace Dachs
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_window->OnUpdate();
		}
	}
}
