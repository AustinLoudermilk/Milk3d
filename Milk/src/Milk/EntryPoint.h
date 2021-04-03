#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern Milk::Application* Milk::CreateApplication();

int main(int argc, char** argv)
{
	Milk::Log::Init();
	Milk::Log::GetCoreLogger()->warn("Logger Initialized");
	Milk::Log::GetClientLogger()->info("Client");

	auto app = Milk::CreateApplication();
	app->Run();
	delete app;
}

#endif
