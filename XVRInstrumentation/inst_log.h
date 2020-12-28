#pragma once
#include"inst_commons.h"
//#pragma warning(push, 0)
#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
//#pragma warning(pop)

namespace xvr
{
	namespace inst
	{
		//class log
		//{

		//public:

		//	log(const log&) = delete;

		//	void operator=(const log&) = delete;


		//	inline static std::shared_ptr<spdlog::logger>& GetLogger() { return Logger; }

		//	static void init(const char* name, const char* filepath = nullptr)
		//	{

		//		if (nullptr != filepath)
		//		{
		//			auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		//			console_sink->set_level(spdlog::level::trace);
		//			console_sink->set_pattern("%^[%T] %n: %v%$");

		//			auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filepath, true);
		//			file_sink->set_level(spdlog::level::trace);
		//			file_sink->set_pattern("%^[%T] %n: %v%$");

		//			spdlog::sinks_init_list sink_list = { file_sink, console_sink };

		//			Logger = std::make_shared<spdlog::logger>(name, sink_list.begin(), sink_list.end());
		//			Logger->set_level(spdlog::level::trace);
		//
		//		}
		//		else
		//		{

		//			auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		//			console_sink->set_level(spdlog::level::trace);
		//			console_sink->set_pattern("%^[%T] %n: %v%$");
		//
		//			Logger = std::make_shared<spdlog::logger>(name, console_sink);
		//			Logger->set_level(spdlog::level::trace);
		//		}
		//

		//


		//	}
		//	static void set_pattern(std::string pattern)
		//	{
		//		Logger->set_pattern(pattern);
		//	}


		//private:
	
		//static std::shared_ptr<spdlog::logger> Logger;
		////static std::shared_ptr<spdlog::logger> Logger;


		//};
		template<typename T>
		using Ref = std::shared_ptr<T>;

		namespace Hazel {

			class Log
			{
			public:
				static void Init();

				static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
				static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
			private:
				static Ref<spdlog::logger> s_CoreLogger;
				static Ref<spdlog::logger> s_ClientLogger;
			};

		}

		// Core log macros
#define HZ_CORE_TRACE(...)    ::xvr::inst::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
//#define HZ_CORE_INFO(...)     ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
//#define HZ_CORE_WARN(...)     ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
//#define HZ_CORE_ERROR(...)    ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define HZ_CORE_CRITICAL(...) ::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)
//
// Client log macros
//#define HZ_TRACE(...)         ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
//#define HZ_INFO(...)          ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
//#define HZ_WARN(...)          ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
//#define HZ_ERROR(...)         ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
//#define HZ_CRITICAL(...)      ::Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)
//
//#define XVR_LOG 1
//#if XVR_LOG 
//
//#define XVR_TRACE(...) ::xvr::inst::log::GetCoreLogger()->trace(__VA_ARGS__)
//#define XVR_INFO(...)  ::xvr::inst::log::GetLogger()->info(__VA_ARGS__)
//#define XVR_WARN(...)  ::xvr::inst::log::GetLogger()->warn(__VA_ARGS__)
//#define XVR_ERROR(...) ::xvr::inst::log::GetLogger()->error(__VA_ARGS__)
//#define XVR_FATAL(...) ::xvr::inst::log::GetLogger()->fatal(__VA_ARGS__)
//#else
//
//#define XVR_TRACE(...) 
//#define XVR_INFO(...)  
//#define XVR_WARN(...)  
//#define XVR_ERROR(...) 
//#define XVR_FATAL(...) 
//
//#endif 
	}
}