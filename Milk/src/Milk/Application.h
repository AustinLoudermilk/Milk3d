#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Milk
{
	
	class MILK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in CLIENT
	Application* CreateApplication();

}

