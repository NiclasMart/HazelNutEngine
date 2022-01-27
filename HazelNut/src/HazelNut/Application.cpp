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
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		CORE_LOG_INFO(e);
		while (true)
		{
		};
	}
}
