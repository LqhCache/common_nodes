#ifndef __LOGGER_LOGAPPENDER_H__
#define __LOGGER_LOGAPPENDER_H__

#include "common/CommonData.h"
#include "logger/LogEvent.h"
#include "logger/Logger.h"
#include "logger/LogFormatter.h"

#include <string>
#include <memory>

namespace logger {
using LogLevel = common::LogLevel;

class Logger;
class LogFormatter;
class LogAppender {
public:
    virtual ~LogAppender() = default;

    virtual void log(const std::shared_ptr<Logger>& logger_ptr, const LogLevel level, const std::shared_ptr<LogEvent>& event) = 0;

    void setFormatter(const std::shared_ptr<LogFormatter>& formatter);
    std::shared_ptr<LogFormatter> getFormatter() const;
protected:
    LogLevel m_level;
    std::shared_ptr<LogFormatter> m_formatter = nullptr;
};
}

#endif