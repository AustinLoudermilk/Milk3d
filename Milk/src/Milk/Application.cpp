#include "Application.h"

#include "./Events/ApplicationEvent.h"
#include "Log.h"

namespace Milk
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
		MK_TRACE(e);

		while (true);
	}
}