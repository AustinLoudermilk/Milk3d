#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Milk 
{
	class MILK_API Log
	{
	public:
		static void  Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log macros
#define MK_CORE_TRACE(...)   ::Milk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MK_CORE_INFO(...)    ::Milk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MK_CORE_WARN(...)    ::Milk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MK_CORE_ERROR(...)   ::Milk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MK_CORE_FATAL(...)   ::Milk::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log macros
#define MK_TRACE(...)        ::Milk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MK_INFO(...)         ::Milk::Log::GetClientLogger()->info(__VA_ARGS__)
#define MK_WARN(...)         ::Milk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MK_ERROR(...)        ::Milk::Log::GetClientLogger()->error(__VA_ARGS__)
#define MK_FATAL(...)        ::Milk::Log::GetClientLogger()->fatal(__VA_ARGS__)