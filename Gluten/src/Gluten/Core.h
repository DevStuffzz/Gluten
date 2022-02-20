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



#ifdef GLUT_ENABLE_ASSERTS
#define GLUT_ASSERT(x, ...) { if(!(x)) { GLUT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define GLUT_CORE_ASSERT(x, ...) { if(!(x)) { GLUT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define GLUT_ASSERT(x, ...)
#define GLUT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GLUT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) 