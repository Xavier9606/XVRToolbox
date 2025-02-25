#pragma once
#include"inst_commons.h"

struct ProfileResult
{
    std::string Name;
    long long Start, End;
    uint32_t ThreadID;
};

struct InstrumentationSession
{
    std::string Name;
};

namespace xvr
{
    namespace inst
    {

        class tracerJSON
        {
        private:
            InstrumentationSession* m_CurrentSession;
            std::ofstream m_OutputStream;
            int m_ProfileCount;
        public:
            tracerJSON()
                : m_CurrentSession(nullptr), m_ProfileCount(0)
            {
            }

            void BeginSession(const std::string& name, const std::string& filepath = "results.json")
            {
                m_OutputStream.open(filepath);
                WriteHeader();
                m_CurrentSession = new InstrumentationSession{ name };
            }

            void EndSession()
            {
                WriteFooter();
                m_OutputStream.close();
                delete m_CurrentSession;
                m_CurrentSession = nullptr;
                m_ProfileCount = 0;
            }

            void WriteProfile(const ProfileResult& result)
            {
                if (m_ProfileCount++ > 0)
                    m_OutputStream << ",";

                std::string name = result.Name;
                std::replace(name.begin(), name.end(), '"', '\'');

                m_OutputStream << "{";
                m_OutputStream << "\"cat\":\"function\",";
                m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
                m_OutputStream << "\"name\":\"" << name << "\",";
                m_OutputStream << "\"ph\":\"X\",";
                m_OutputStream << "\"pid\":0,";
                m_OutputStream << "\"tid\":" << result.ThreadID << ",";
                m_OutputStream << "\"ts\":" << result.Start;
                m_OutputStream << "}";

                m_OutputStream.flush();
            }

            void WriteHeader()
            {
                m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
                m_OutputStream.flush();
            }

            void WriteFooter()
            {
                m_OutputStream << "]}";
                m_OutputStream.flush();
            }

            static tracerJSON& Get()
            {
                static tracerJSON instance;
                return instance;
            }
        };

    }
}