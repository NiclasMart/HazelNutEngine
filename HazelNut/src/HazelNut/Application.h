#pragma once

#include "Core.h";

namespace HazelNut {

	class HAZELNUT_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

	};

	//Implemented by the client
	Application* CreateApplication();

}