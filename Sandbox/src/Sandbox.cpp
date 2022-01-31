// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <HazelNut.h>

class ExampleLayer : public HazelNut::Layer
{
public:
	ExampleLayer()
		:Layer("ExampleLayer")
	{}

	virtual void OnUpdate() override
	{
		LOG_TRACE("Update on Example Layer called!");
	}

	virtual void OnEvent(HazelNut::Event& event) override
	{
		LOG_TRACE("{1}", event);
		event.Handled = true;
	}

};


class Sandbox : public HazelNut::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new HazelNut::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

HazelNut::Application* HazelNut::CreateApplication()
{
	return new Sandbox();
}


