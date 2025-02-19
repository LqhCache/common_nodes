#ifndef __LOGGER_FILELOGAPPENDER_H__
#define __LOGGER_FILELOGAPPENDER_H__

#include "common/CommonData.h"
#include "logger/LogEvent.h"
#include "logger/LogAppender.h"

#include <string>
#include <fstream>
#include <memory>

namespace logger {
using LogLevel = common::LogLevel;

class FileLogAppender : public LogAppender {
public:
    FileLogAppender(const std::string& filename);
    void log(const std::shared_ptr<Logger>& logger_ptr, const LogLevel level, const std::shared_ptr<LogEvent>& event) override;

    bool reopen();
private:
    std::string m_filename;
    std::ofstream m_filestream;
};
}

#endif