#ifndef LOGGER_H
#define LOGGER_H

#include <cstdarg>
#include <cstring>
#include <fstream>
#include <iostream>
#include <mutex>
#include <stdio.h>
#include "TimeStamp/Timestamp.h"

namespace pjie {

enum Priority {
    LOG_DEBUG = 0,
    LOG_STATE,
    LOG_INFO,
    LOG_WARINING,
    LOG_ERROR,
};

class Logger {
public:
    Logger(const Logger& other) = delete;
    Logger& operator=(const Logger& other) = delete;
    Logger(const Logger*) = delete;
    static Logger& Instance()
    {
        static Logger log;
        return log;
    }
    ~Logger()
    {
    }

    void Init(const char* pathname = nullptr)
    {
        std::unique_lock<std::mutex> lk(mtx_);
        if (pathname != nullptr) {
            ofs_.open(pathname, std::ios::out | std::ios::binary);
            if (ofs_.fail()) {
                std::cerr << "Fiailed to open logfile" << std::endl;
            }
        }
    }

    void Exit()
    {
        std::unique_lock<std::mutex> lk(mtx_);
        if (ofs_.is_open()) {
            ofs_.close();
        }
    }

    void log(Priority priority, const char* file, const char* func, int Line,
        const char* fmt, ...)
    {
        std::unique_lock<std::mutex> lk(mtx_);

        char buf[2048] = { 0 };
        snprintf(buf,sizeof(buf), "[%s][%s:%s:%d]", Priority_To_String[priority],
            file, func, Line);
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf + strlen(buf),sizeof(buf)-strlen(buf), fmt, args);
        va_end(args);
        this->Write(buf);
    }

    void Write(std::string str)
    {
        if (ofs_.is_open()) {
            ofs_ << "[" << Timestamp::Localtime() << "]" << str;
        }
        std::cout << "[" << Timestamp::Localtime() << "]" << str << std::endl;
    }

private:
    Logger() { }

    std::mutex mtx_;
    std::ofstream ofs_;

    const char* Priority_To_String[5] = {
        "DEBUG",
        "CONFIG",
        "INFO",
        "WARNING",
        "ERROR"
    };
};

}

#define LOG_DEBUG(fmt, ...) pjie::Logger::Instance().log(pjie::Priority::LOG_DEBUG, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#endif