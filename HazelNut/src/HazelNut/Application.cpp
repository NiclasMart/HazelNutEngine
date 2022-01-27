#include "hzn_pch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "HazelNut/Log.h"

namespace HazelNut {
	
	Application::Application()
	{
		Logger = std::make_unique<Log>();
		Logger->Init();
		CORE_LOG_WARN("Initialized Logger");

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		};
	}
}
