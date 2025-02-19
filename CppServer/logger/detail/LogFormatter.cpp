#include "logger/LogFormatter.h"

#include <map>
#include <tuple>
#include <iostream>
#include <functional>

namespace {
using LogLevel = common::LogLevel;
using LogEvent = logger::LogEvent;
using Logger = logger::Logger;

class StringFormatItem : public logger::LogFormatter::FormatItem {
public:
    StringFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
private:
    std::string m_string;
};

class NameFormatItem : public logger::LogFormatter::FormatItem {
public:
    NameFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class MessageFormatItem : public logger::LogFormatter::FormatItem {
public:
    MessageFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class LineFormatItem : public logger::LogFormatter::FormatItem {
public:
    LineFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class NewLineFormatItem : public logger::LogFormatter::FormatItem {
public:
    NewLineFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class LevelFormatItem : public logger::LogFormatter::FormatItem {
public:
    LevelFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class ElapseFormatItem : public logger::LogFormatter::FormatItem {
public:
    ElapseFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class FilenameFormatItem : public logger::LogFormatter::FormatItem {
public:
    FilenameFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class ThreadIdFormatItem : public logger::LogFormatter::FormatItem {
public:
    ThreadIdFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class FiberIdFormatItem : public logger::LogFormatter::FormatItem {
public:
    FiberIdFormatItem(const std::string& str);
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
};

class DateTimeFormatItem : public logger::LogFormatter::FormatItem {
public:
    DateTimeFormatItem(const std::string& format = "%Y:%M:%D %H:%M:%S");
    void format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                const LogLevel level, const std::shared_ptr<LogEvent>& event) override;
private:
    std::string m_format;
};

StringFormatItem::StringFormatItem(const std::string& str)
    : FormatItem(str), m_string(str)
{
}

void StringFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                               const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << m_string;
}

NameFormatItem::NameFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void NameFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                               const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << logger_ptr->getName();
}

MessageFormatItem::MessageFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void MessageFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                               const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << event->getContent();
}

LineFormatItem::LineFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void LineFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                            const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << event->getLine();
}

NewLineFormatItem::NewLineFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void NewLineFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                            const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << std::endl;
}

LevelFormatItem::LevelFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void LevelFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                             const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << common::logLeveltoString(level);
}

ElapseFormatItem::ElapseFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void ElapseFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                              const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << event->getElapse();
}

FilenameFormatItem::FilenameFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void FilenameFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                                const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << event->getFile();
}

ThreadIdFormatItem::ThreadIdFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void ThreadIdFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                                const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << event->getThreadId();
}

FiberIdFormatItem::FiberIdFormatItem(const std::string& str)
    : FormatItem(str)
{
}

void FiberIdFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                                const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << event->getFiberId();
}

DateTimeFormatItem::DateTimeFormatItem(const std::string& format)
    : m_format(format)
{
}

void DateTimeFormatItem::format(std::ostream& os, const std::shared_ptr<Logger>& logger_ptr, 
                                const LogLevel level, const std::shared_ptr<LogEvent>& event) 
{
    os << event->getTime();
}
}

namespace logger {
LogFormatter::LogFormatter(const std::string& pattern) 
    : m_pattern(pattern)
{
}

LogFormatter::FormatItem::FormatItem(const std::string& fmt)
    : m_format(fmt)
{
}

std::string LogFormatter::format(const std::shared_ptr<Logger>& logger_ptr, const LogLevel level, 
                                 const std::shared_ptr<LogEvent>& event)
{
    std::stringstream ss;
    for (const auto& item : m_items) {
        item->format(ss, logger_ptr, level, event);
    }
    return ss.str();
}

// %xxx %xxx{xxx} %%
void LogFormatter::init() 
{
    std::vector<std::tuple<std::string, std::string, int>> vec;
    std::string str;
    for (size_t i = 0; i < m_pattern.size(); ++ i) {
        if (m_pattern[i] != '%') {
            str += m_pattern[i];
            continue;
        }
        if ((i + 1) < m_pattern.size() && m_pattern[i + 1] == '%') {
            str += '%';
            continue;
        }

        size_t n = i + 1;
        int fmt_status = 0;
        size_t fmt_begin = 0;
        std::string istr;
        std::string fmt;
        while (n < m_pattern.size()) {
            if (std::isspace(m_pattern[n])) {
                break;
            }
            if (fmt_status == 0) {
                if (m_pattern[n] == '{') {
                    istr = m_pattern.substr(i + 1, n - i - 1);
                    fmt_status = 1;
                    fmt_begin = n;
                    ++ n;
                    continue;
                }
            }
            if (fmt_status == 1) {
                if (m_pattern[n] == '}') {
                    fmt = m_pattern.substr(fmt_begin + 1, n - fmt_begin - 1);
                    fmt_status = 2;
                    break;
                }
            }
        }

        if (fmt_status == 0) {
            if (!str.empty()) {
                vec.emplace_back(std::make_tuple(str, "", 0));
            }
            istr = m_pattern.substr(i + 1, n - i - 1);
            vec.emplace_back(std::make_tuple(istr, fmt, 1));
            i = n;
        } else if (fmt_status == 1) {
            std::cout << "pattern parse error: " << m_pattern << " - " << m_pattern.substr(i) << std::endl;
            vec.emplace_back(std::make_tuple("<<pattern_error>>", fmt, 0));
        } else if (fmt_status == 2) {
            if (str.empty()) {
                vec.emplace_back(std::make_tuple(str, "", 0));
            }
            vec.emplace_back(std::make_tuple(istr, fmt, 1));
            i = n;
        }
    }

    if (!str.empty()) {
        vec.emplace_back(std::make_tuple(str, "", 0));
    }

    static std::map<std::string, std::function<std::shared_ptr<LogFormatter::FormatItem>(const std::string& fmt)>> s_format_items = {
#define XX(str, C) \
        {#str, [](const std::string& fmt) { return std::make_shared<C>(fmt); }}

        XX(m, MessageFormatItem),   // %m -- 消息体
        XX(p, LevelFormatItem),     // %p -- level
        XX(r, ElapseFormatItem),    // %r -- 启动后的时间
        XX(c, NameFormatItem),      // %c -- 日志名称
        XX(t, ThreadIdFormatItem),  // %t -- 线程id
        XX(n, NewLineFormatItem),   // %n -- 回车换行
        XX(d, DateTimeFormatItem),  // %d -- 时间
        XX(f, FilenameFormatItem),  // %f -- 文件名
        XX(l, LineFormatItem),      // %l -- 行号
#undef XX
    };

    for (const auto& v : vec) {
        if (std::get<2>(v) == 0) {
            m_items.emplace_back(std::make_shared<StringFormatItem>(std::get<0>(v)));
        }else {
            auto it = s_format_items.find(std::get<0>(v));
            if (it == s_format_items.end()) {
                m_items.emplace_back(std::make_shared<StringFormatItem>("<<error_format %" + std::get<0>(v) + ">>"));
            } else {
                m_items.emplace_back(it->second(std::get<1>(v)));
            }

            std::cout << std::get<0>(v) << " - " << std::get<1>(v) << " - " << std::get<2>(v) << std::endl;
        }
    }
}
}