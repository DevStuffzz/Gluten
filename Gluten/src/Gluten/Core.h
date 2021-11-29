#pragma once

#ifdef GLUT_PLATFORM_WINDOWS
#ifdef GLUT_BUILD_DLL
#define GLUT_API __declspec(dllexport)
#else
#define GLUT_API __declspec(dllimport)
#endif
#else
#error Gluten only supports Windows!
#endif