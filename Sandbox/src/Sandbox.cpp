#include <Milk.h>

class Sandbox : public Milk::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Milk::Application* Milk::CreateApplication()
{
	return new Sandbox();
}