#pragma once

#include "Core.h"
#include "Window.h"

#include "LayerStack.h"


namespace HazelNut {

	class HAZELNUT_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

		void OnEvent(Event& event);

		void PushLayer(class Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() const { return *m_Window; }
	private:
		bool OnWindowClose(class WindowCloseEvent& e);

		std::unique_ptr<Log> Logger;
		std::unique_ptr<Window> m_Window;

		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//Implemented by the client
	Application* CreateApplication();

}