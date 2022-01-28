#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"


namespace HazelNut {

	class HAZELNUT_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& event);
	private:
		bool OnWindowClose(class WindowCloseEvent& e);

		std::unique_ptr<Log> Logger;
		std::unique_ptr<Window> m_Window;

		bool m_Running = true;

	};

	//Implemented by the client
	Application* CreateApplication();

}