#include"inst_log.h"
//#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

//namespace xvr
//{
//	namespace inst
//	{
//		std::shared_ptr<spdlog::logger> log::s_CoreLogger;
//		std::shared_ptr<spdlog::logger> log::s_ClientLogger;
//
//		void xvr::inst::log::Init()
//		{
//			std::vector<spdlog::sink_ptr> logSinks;
//			logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
//			logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Hazel.log", true));
//
//			logSinks[0]->set_pattern("%^[%T] %n: %v%$");
//			logSinks[1]->set_pattern("[%T] [%l] %n: %v");
//
//			s_CoreLogger = std::make_shared<spdlog::logger>("HAZEL", begin(logSinks), end(logSinks));
//			spdlog::register_logger(s_CoreLogger);
//			s_CoreLogger->set_level(spdlog::level::trace);
//			s_CoreLogger->flush_on(spdlog::level::trace);
//
//			s_ClientLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
//			spdlog::register_logger(s_ClientLogger);
//			s_ClientLogger->set_level(spdlog::level::trace);
//			s_ClientLogger->flush_on(spdlog::level::trace);
//		}
//
//	}
//}

template<typename T>
using Ref = std::shared_ptr<T>;



namespace xvr
{
	namespace inst
	{
		namespace Hazel
		{

			Ref<spdlog::logger> Log::s_CoreLogger;
			Ref<spdlog::logger> Log::s_ClientLogger;

			void Log::Init()
			{
				std::vector<spdlog::sink_ptr> logSinks;
				logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
				logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Hazel.log", true));

				logSinks[0]->set_pattern("%^[%T] %n: %v%$");
				logSinks[1]->set_pattern("[%T] [%l] %n: %v");

				s_CoreLogger = std::make_shared<spdlog::logger>("HAZEL", begin(logSinks), end(logSinks));
				spdlog::register_logger(s_CoreLogger);
				s_CoreLogger->set_level(spdlog::level::trace);
				s_CoreLogger->flush_on(spdlog::level::trace);

				s_ClientLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
				spdlog::register_logger(s_ClientLogger);
				s_ClientLogger->set_level(spdlog::level::trace);
				s_ClientLogger->flush_on(spdlog::level::trace);
			}

		}
	}
}