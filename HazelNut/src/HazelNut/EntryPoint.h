#pragma once

#ifdef HZN_PLATFORM_WINDOWS

// application comes from the client
extern HazelNut::Application* HazelNut::CreateApplication();
	
int main(int argc, char** argv)
{
	auto app = HazelNut::CreateApplication();
	app->Run();
	delete app;
}

#endif
