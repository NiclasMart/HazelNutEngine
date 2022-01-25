#pragma once

#include "Core.h"
#include "Log.h"

namespace HazelNut {

	class HAZELNUT_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	private:
		std::unique_ptr<Log> Logger;

	};

	//Implemented by the client
	Application* CreateApplication();

}