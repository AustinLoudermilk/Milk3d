#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern Milk::Application* Milk::CreateApplication();

int main(int argc, char** argv) {
	auto app = Milk::CreateApplication();
	app->Run();
	delete app;
}

#endif
