#include "logger/StdoutLogAppender.h"

#include <iostream>

namespace logger {
void StdoutLogAppender::log(const std::shared_ptr<Logger>& logger_ptr, const LogLevel level, const std::shared_ptr<LogEvent>& event)
{
    if (level > m_level) {
        std::cout << m_formatter->format(logger_ptr, level, event);
    }
}
}