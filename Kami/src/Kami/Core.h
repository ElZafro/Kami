#pragma once

#ifdef KM_PLATFORM_WINDOWS
#ifdef KM_BUILD_DLL
#define KAMI_API __declspec(dllexport)
#else 
#define KAMI_API __declspec(dllimport)
#endif
#else 
#error Kami only supports Windows!
#endif