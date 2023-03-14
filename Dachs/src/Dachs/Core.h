#pragma once

#ifdef DS_PLATFORM_WINDOWS
	#ifdef DS_BUILD_DLL
		#define DACHS_API __declspec(dllexport)
	#else
		#define DACHS_API __declspec(dllimport)
	#endif // DS_BUILD_DLL
#else
	#error Platform not supported
#endif // DS_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

#ifdef DS_ENABLE_ASSERTS
	#define DS_CLIENT_ASSERT(x, ...) { if(!(x)) { DS_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DS_CORE_ASSERT(x, ...) { if(!(x)) { DS_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DS_CLIENT_ASSERT(x, ...)
	#define DS_CORE_ASSERT(x, ...)
#endif
