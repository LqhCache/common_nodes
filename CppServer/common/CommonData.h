#ifndef __LOGGER_LOGGERAPPENDER_H__
#define __LOGGER_LOGGERAPPENDER_H__

namespace common {
enum class LogLevel {
    UNKNOW = 0,
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5
};

const char* logLeveltoString(const LogLevel level) 
{
    switch (level) {
#define XX(name) \
    case LogLevel::name: \
        return #name; \
        break;
    
    XX(DEBUG);
    XX(INFO);
    XX(WARN);
    XX(ERROR);
    XX(FATAL);
#undef XX
    default:
        return "UNKNOW";
    }
}
}

#endif