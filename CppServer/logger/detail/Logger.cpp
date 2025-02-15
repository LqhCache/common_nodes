#include "logger/Logger.h"

namespace logger::detail {
Logger::Logger(const std::string& name)
    : m_name(name)
{
}

void Logger::setLogLevel(const LogLevel level)
{
    m_level = level;
}

LogLevel Logger::getLogLevel()
{
    return m_level;
}

void Logger::log(LogLevel level, const std::shared_ptr<LogEvent>& event)
{
    if (level >= m_level) {
        for (const auto& appender : m_appenders) {
            appender->log(level, event);
        }
    }
}

void Logger::debug(const std::shared_ptr<LogEvent>& event)
{
    debug(LogLevel::DEBUG, event);
}

void Logger::info(const std::shared_ptr<LogEvent>& event)
{
    debug(LogLevel::INFO, event);
}

void Logger::warn(const std::shared_ptr<LogEvent>& event)
{
    debug(LogLevel::WARN, event);
}

void Logger::error(const std::shared_ptr<LogEvent>& event)
{
    debug(LogLevel::ERROR, event);
}

void Logger::fatal(const std::shared_ptr<LogEvent>& event)
{
    debug(LogLevel::FATAL, event);
}

void Logger::addAppender(const std::shared_ptr<LogAppender>& appender)
{
    m_appenders.emplace(appender);
}

void Logger::delAppender(const std::shared_ptr<LogAppender>& appender)
{
    const auto iter = m_appenders.find(appender);
    if (iter != m_appenders.end()) {
        m_appenders.erase(iter);
    }
}
}