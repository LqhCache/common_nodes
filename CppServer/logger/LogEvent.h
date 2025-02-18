#ifndef __LOGGER_LOGGEREVENT_H__
#define __LOGGER_LOGGEREVENT_H__

#include <string>
#include <stdint.h>

namespace logger {
class LogEvent {
public:
    LogEvent() = default;

    const char* getFile() const;
    int32_t getLine() const;
    uint32_t getElapse() const;
    uint32_t getThreadId() const;
    uint32_t getFiberId() const;
    uint64_t getTime() const;
    const std::string& getContent() const;
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