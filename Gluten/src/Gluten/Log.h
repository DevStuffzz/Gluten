#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Gluten {
	class GLUT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

// Core log macros
#define GLUT_CORE_TRACE(...)    ::Gluten::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GLUT_CORE_INFO(...)     ::Gluten::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GLUT_CORE_WARN(...)     ::Gluten::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GLUT_CORE_ERROR(...)    ::Gluten::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GLUT_CORE_FATAL(...)    ::Gluten::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define GLUT_TRACE(...)	      ::Gluten::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GLUT_INFO(...)	      ::Gluten::Log::GetClientLogger()->info(__VA_ARGS__)
#define GLUT_WARN(...)	      ::Gluten::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GLUT_ERROR(...)	      ::Gluten::Log::GetClientLogger()->error(__VA_ARGS__)
#define GLUT_FATAL(...)	      ::Gluten::Log::GetClientLogger()->fatal(__VA_ARGS__)
}
