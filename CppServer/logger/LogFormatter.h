#ifndef __LOGGER_LOGFORMATTER_H__
#define __LOGGER_LOGFORMATTER_H__

#include "common/CommonData.h"
#include "logger/LogEvent.h"

#include <memory>
#include <sstream>

namespace logger {
using LogLevel = common::LogLevel;

class LogFormatter {
public:
    class FormatItem {
    public:
        virtual ~FormatItem() {}
        virtual void format(std::ostream& os, const LogLevel level, std::shared_ptr<LogEvent>& event) = 0;
    };

    LogFormatter(const std::string& pattern);

    std::string format(const LogLevel level, const std::shared_ptr<LogEvent>& event);
    void init();

private:
    std::string m_pattern;
    std::vector<std::shared_ptr<FormatItem>> m_items;
};
}

#endif