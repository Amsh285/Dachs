

#include <Dachs.h>

class Sandbox : public Dachs::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Dachs::Application* Dachs::CreateApplication()
{
	return new Sandbox();
}
