#ifndef __LOGGER_LOGFORMATTER_H__
#define __LOGGER_LOGFORMATTER_H__

#include "logger/LogEvent.h"

#include <memory>

namespace logger {
class LogFormatter {
public:
    std::string format(const std::shared_ptr<LogEvent>& event);
private:

};
}

#endif