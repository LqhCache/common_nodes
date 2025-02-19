#include "logger/FileLogAppender.h"

namespace logger {
FileLogAppender::FileLogAppender(const std::string& filename) 
    : m_filename(filename)
{
}

void FileLogAppender::log(const std::shared_ptr<Logger>& logger_ptr, const LogLevel level, const std::shared_ptr<LogEvent>& event)
{
    if (level >= m_level) {
        m_filestream << m_formatter->format(logger_ptr, level, event);
    }
}

bool FileLogAppender::reopen() 
{
    if (m_filestream) {
        m_filestream.close();
    }
    m_filestream.open(m_filename);
    return !!m_filestream;
}
}