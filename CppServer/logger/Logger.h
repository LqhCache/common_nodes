#ifndef __LOGGER_LOGGER_H__
#define __LOGGER_LOGGER_H__

#include "common/CommonData.h"
#include "logger/LogEvent.h"
#include "logger/LogAppender.h"

#include <unordered_set>
#include <string>
#include <memory>

namespace logger {
using LogLevel = common::LogLevel;

class LogAppender;
class Logger {
public:
    Logger(const std::string& name = "root");
    void log(const LogLevel level, const std::shared_ptr<LogEvent>& event);

    void setLogLevel(const LogLevel level);
    LogLevel getLogLevel();
    std::string getName();

    void debug(const std::shared_ptr<LogEvent>& event);
    void info(const std::shared_ptr<LogEvent>& event);
    void warn(const std::shared_ptr<LogEvent>& event);
    void error(const std::shared_ptr<LogEvent>& event);
    void fatal(const std::shared_ptr<LogEvent>& event);

    void addAppender(const std::shared_ptr<LogAppender>& appender);
    void delAppender(const std::shared_ptr<LogAppender>& appender);
private:
    std::string m_name;
    LogLevel m_level;
    std::unordered_set<std::shared_ptr<LogAppender>> m_appenders; 
};
}

#endif