#include "logger/StdoutLogAppender.h"

namespace logger::detail {
void StdoutLogAppender::log(LogLevel level, const std::shared_ptr<LogEvent>& event)
{
    if (level > m_level) {
        std::cout << m_formatter.format(event);
    }
}
}