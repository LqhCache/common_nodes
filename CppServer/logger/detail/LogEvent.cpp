#include "logger/LogEvent.h"

namespace logger {
const char* LogEvent::getFile() const
{
    return m_file;
}

int32_t LogEvent::getLine() const
{
    return m_line;
}

uint32_t LogEvent::getElapse() const
{
    return m_elapse;
}

uint32_t LogEvent::getThreadId() const
{
    return m_thread_id;
}

uint32_t LogEvent::getFiberId() const
{
    return m_fiber_id;
}

uint64_t LogEvent::getTime() const
{
    return m_time;
}

const std::string& LogEvent::getContent() const
{
    return m_content;
}

}