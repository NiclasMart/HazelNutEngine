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

#ifdef HZN_DEBUG
	#define HZN_ENABLE_ASSERTS
#endif

#ifdef HZN_ENABLE_ASSERTS
	#define HZN_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HZN_CORE_ASSERT(x, ...) { if(!(x)) { CORE_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HZN_ASSERT(x, ...)
	#define HZN_CORE_ASSERT(x, ...)
#endif

#define SET_BITMAP(x) (1 << (x))
