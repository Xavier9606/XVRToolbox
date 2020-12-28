#pragma once
#include"inst_commons.h"
#include"inst_tracerjson.h"
namespace xvr
{
	namespace inst
	{

		class scoped_timer
		{

		public:
			scoped_timer(const char* name)
				: m_Name(name), m_Stopped(false)
			{
				m_StartTimepoint = std::chrono::high_resolution_clock::now();
			}

			~scoped_timer()
			{
				if(!m_Stopped)
				Stop();
			}

			void Stop()
			{
				auto endTimepoint = std::chrono::high_resolution_clock::now();
				auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
				auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
				auto duration = end - start;
				

				m_Stopped = true;
				uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
				tracerJSON::Get().WriteProfile({ m_Name, start, end, threadID });

			}
		private:
			const char* m_Name;
			std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
			bool m_Stopped;



		};

		template<typename Fn>
		class scoped_timer_cb
		{

		public:
			scoped_timer_cb(const char* name, Fn&& func)
				: m_Name(name), m_Func(func), m_Stopped(false)
			{
				m_StartTimepoint = std::chrono::high_resolution_clock::now();
			}

			~scoped_timer_cb()
			{
				if (!m_Stopped)
					Stop();
			}

			void Stop()
			{
				auto endTimepoint = std::chrono::high_resolution_clock::now();
				auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
				auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
				auto duration = end - start;


				m_Stopped = true;
				m_Func(duration);
			}
		private:
			const char* m_Name;
			Fn m_Func;
			std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
			bool m_Stopped;

		};


	}
}