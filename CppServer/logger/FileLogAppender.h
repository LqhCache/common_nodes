#ifndef __LOGGER_FILELOGAPPENDER_H__
#define __LOGGER_FILELOGAPPENDER_H__

#include "common/CommonData.h"
#include "logger/LogEvent.h"

#include <string>
#include <fstream>

namespace logger {
class FileLogAppender : public LogAppender {
public:
    FileLogAppender(const std::string& filename);
    void log(LogLevel level, const std::shared_ptr<LogEvent>& event) override;

    bool reopen();
private:
    std::string m_filename;
    std::ofstream m_filestream;
};
}

#endif