#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern Milk::Application* Milk::CreateApplication();

int main(int argc, char** argv)
{
	Milk::Log::Init();

	MK_CORE_WARN("Engine logger initialized");
	MK_WARN("Client logger initialized");
	
	auto app = Milk::CreateApplication();
	app->Run();
	delete app;
}

#endif
