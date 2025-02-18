#include "logger/LogFormatter.h"

#include <tuple>

namespace {
class MessageFormatItem : public logger::LogFormatter::FormatItem {
public:
    void format(std::ostream& os, const LogLevel level, std::shared_ptr<LogEvent>& event) override;
};

class LevelFormatItem : public logger::LogFormatter::FormatItem {
public:
    void format(std::ostream& os, const LogLevel level, std::shared_ptr<LogEvent>& event) override;
};

void MessageFormatItem::format(std::ostream& os, const LogLevel level, std::shared_ptr<LogEvent>& event) 
{
    os << event->getContent();
}

void LevelFormatItem::format(std::ostream& os, const LogLevel level, std::shared_ptr<LogEvent>& event) 
{
    os << common::logLeveltoString(level);
}

}

namespace logger::detail {
LogFormatter::LogFormatter(const std::string& pattern) 
    : m_pattern(pattern)
{
}

std::string LogFormatter::format(const LogLevel level, const std::shared_ptr<LogEvent>& event)
{
    std::stringstream ss;
    for (const auto& item : m_items) {
        item->format(ss, level, event);
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

    // %n -- 消息体
    // %p -- level
    // %r -- 启动后的时间
    // %c -- 日志名称
    // %t -- 线程id
    // %n -- 回车换行
    // %d -- 时间
    // %f -- 文件名
    // %l -- 行号
}
}