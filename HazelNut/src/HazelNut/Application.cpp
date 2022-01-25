#include "Application.h"

#include <memory>

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
		while (true)
		{
		};
	}
}
