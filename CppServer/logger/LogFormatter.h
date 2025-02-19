#ifndef __LOGGER_LOGFORMATTER_H__
#define __LOGGER_LOGFORMATTER_H__

#include "common/CommonData.h"
#include "logger/LogEvent.h"
#include "logger/Logger.h"

#include <memory>
#include <sstream>
#include <vector>

namespace logger {
using LogLevel = common::LogLevel;

class Logger;
class LogFormatter {
public:
    class FormatItem {
    public:
        FormatItem(const std::string& fmt = "");
        virtual ~FormatItem() {}
        virtual void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                            const LogLevel level, const std::shared_ptr<LogEvent>& event) = 0;
    private:
        std::string m_format;
    };

    LogFormatter(const std::string& pattern);

    std::string format(const std::shared_ptr<Logger>& logger_ptr, const LogLevel level, const std::shared_ptr<LogEvent>& event);
    void init();

private:
    std::string m_pattern;
    std::vector<std::shared_ptr<FormatItem>> m_items;
};
}

#endif