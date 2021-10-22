#pragma once
#ifdef NITROZ_WINDOWS
	#ifdef NITROZ_LIB
		#define NITROZ_API __declspec(dllexport)
	#else
		#define NITROZ_API __declspec(dllexport)
	#endif
#else
	#define NITROZ_API
#endif