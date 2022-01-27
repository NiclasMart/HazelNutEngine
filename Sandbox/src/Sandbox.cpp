#include <HazelNut.h>


class Sandbox : public HazelNut::Application
{
public:
	Sandbox()
	{
		LOG_INFO("Initialized App!");
	}

	~Sandbox()
	{

	}

};

HazelNut::Application* HazelNut::CreateApplication()
{
	return new Sandbox();
}


