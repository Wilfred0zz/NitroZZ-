#pragma once
#ifdef NITROZ_WINDOWS
	#ifdef NITROZ_LIB
		#define NITROZ_API __declspec(dllexport)
	#else
		#define NITROZ_API __declspec(dllimport)
	#endif
#else
	#define NITROZ_API
#endif

#ifdef NITROZ_DEBUG
	#define NITROZ_LOG(x) std::cout<<x<<std::endl;
#else 
	#define NITROZ_LOG(x)
#endif