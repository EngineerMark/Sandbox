#pragma once

#ifdef __unix__      
#define OS_LINUX
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif

static bool IsDebugMode() {
#ifdef _DEBUG
	return true;
#else
	return false;
#endif
}