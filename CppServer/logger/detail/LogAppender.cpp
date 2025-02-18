#include "logger/LogAppender.h"

namespace logger::detail {
void LogAppender::setFormatter(const std::shared_ptr<LogFormatter>& formatter)
{
    m_formatter = formatter;
}

std::shared_ptr<LogFormatter> LogAppender::getFormatter() const
{
    return m_formatter;
}
}