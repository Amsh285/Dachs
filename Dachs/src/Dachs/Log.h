#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Dachs
{
	class DACHS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define DS_CORE_TRACE(...)     ::Dachs::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DS_CORE_INFO(...)      ::Dachs::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DS_CORE_WARN(...)      ::Dachs::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DS_CORE_ERROR(...)     ::Dachs::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DS_CORE_FATAL(...)     ::Dachs::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define DS_CLIENT_TRACE(...)   ::Dachs::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DS_CLIENT_INFO(...)    ::Dachs::Log::GetClientLogger()->info(__VA_ARGS__)
#define DS_CLIENT_WARN(...)    ::Dachs::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DS_CLIENT_ERROR(...)   ::Dachs::Log::GetClientLogger()->error(__VA_ARGS__)
#define DS_CLIENT_FATAL(...)   ::Dachs::Log::GetClientLogger()->fatal(__VA_ARGS__)
