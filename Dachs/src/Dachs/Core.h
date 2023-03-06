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
