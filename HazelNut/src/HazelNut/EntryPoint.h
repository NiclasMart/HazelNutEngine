// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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
