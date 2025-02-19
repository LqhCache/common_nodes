#ifndef __LOGGER_STDOUTLOGAPPENDER_H__
#define __LOGGER_STDOUTLOGAPPENDER_H__

#include "common/CommonData.h"
#include "logger/LogEvent.h"
#include "logger/LogAppender.h"

#include <string>

namespace logger {
class StdoutLogAppender : public LogAppender {
public:
    void log(const std::shared_ptr<Logger>& logger_ptr, const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
private:
};
}

#endif