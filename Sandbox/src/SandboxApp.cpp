#include <Milk.h>

class ExampleLayer : public Milk::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//MK_INFO("ExampleLayer::Update");
	}

	void OnEvent(Milk::Event& event) override
	{
		MK_TRACE("{0}", event);
	}
};

class Sandbox : public Milk::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Milk::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Milk::Application* Milk::CreateApplication()
{
	return new Sandbox();
}