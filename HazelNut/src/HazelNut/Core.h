#pragma once

//checks if the current platform is windows (macro is defined in settings)
#ifdef HZN_PLATFORM_WINDOWS
	//checks for defined macro which indicates that the HazelNut dll is build
	#ifdef HZN_BUILD_DLL
		#define HAZELNUT_API __declspec(dllexport)
	#else
		#define HAZELNUT_API __declspec(dllimport)
	#endif
#else
	#error HazelNut only supports Windows!
#endif

#define BIT(x) (1 << x)
