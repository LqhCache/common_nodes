#ifndef __LOGGER_LOGGEREVENT_H__
#define __LOGGER_LOGGEREVENT_H__

#include <string>
#include <stdint.h>

namespace logger {
class LogEvent {
public:
    LogEvent() = default;

private:
    const char* m_file = nullptr;
    int32_t m_line = 0;
    uint32_t m_elapse = 0;
    unit32_t m_thread_id = 0;
    unit32_t m_fiber_id = 0;
    uint64_t m_time;
    std::string m_content;
};
}

#endif