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
		if (HazelNut::Input::IsKeyPressed(HZN_KEY_A))
		{
			LOG_TRACE("Button A was pressed (polling).");
		}
	}

	virtual void OnEvent(HazelNut::Event& event) override
	{
		LOG_TRACE("Button A was pressed (event).");
		if (event.GetEventType() == HazelNut::EventType::KeyPressed)
		{
			HazelNut::KeyPressedEvent& e = (HazelNut::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZN_KEY_A)
			{
				LOG_TRACE("Button A was pressed (event).");
			}
		}
	}

};


class Sandbox : public HazelNut::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		auto UI = new HazelNut::ImGuiLayer();
		PushOverlay(UI);
		//UI->CreateUIWindow();
	}

	~Sandbox()
	{

	}

};

HazelNut::Application* HazelNut::CreateApplication()
{
	return new Sandbox();
}


