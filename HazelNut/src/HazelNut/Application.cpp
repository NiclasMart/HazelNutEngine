#include "hzn_pch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "HazelNut/LayerStack.h"
#include "HazelNut/Layer.h"

#include <GLFW/glfw3.h>

namespace HazelNut {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	
	Application::Application()
	{
		Logger = std::make_unique<Log>();
		Logger->Init();
		CORE_LOG_WARN("Initialized Logger");

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		};
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		m_LayerStack.PassEventToLayers(event);
	}

	void Application::PushLayer(class Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}


	

}
