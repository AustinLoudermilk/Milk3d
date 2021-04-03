#pragma once

#ifdef MK_PLATFORM_WINDOWS
	#ifdef MK_BUILD_DLL
		#define MILK_API __declspec(dllexport)
	#else
		#define MILK_API __declspec(dllimport)
	#endif
#else
	#error Milk only supports Windows!
#endif

#define BIT(x) (1 << x)