#pragma once

#include "Core.h"

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

