#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern Milk::Application* Milk::CreateApplication();

int main(int argc, char** argv)
{
	Milk::Log::Init();
	MK_CORE_WARN("Logger Initialized");
	MK_INFO("Client");
	
	auto app = Milk::CreateApplication();
	app->Run();
	delete app;
}

#endif
