#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace HazelNut {

	class HAZELNUT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//core log macros
#define CORE_LOG_TRACE(...) HazelNut::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_LOG_INFO(...)  HazelNut::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_LOG_WARN(...)  HazelNut::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_LOG_ERROR(...) HazelNut::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_LOG_FATAL(...) HazelNut::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define LOG_TRACE(...) HazelNut::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)  HazelNut::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)  HazelNut::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) HazelNut::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) HazelNut::Log::GetClientLogger()->fatal(__VA_ARGS__)


