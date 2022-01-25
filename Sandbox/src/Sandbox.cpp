#include <HazelNut.h>


class Sandbox : public HazelNut::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

HazelNut::Application* HazelNut::CreateApplication()
{
	return new Sandbox();
}


