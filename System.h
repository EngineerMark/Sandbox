#pragma once

#ifdef __unix__      
#define OS_LINUX
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif