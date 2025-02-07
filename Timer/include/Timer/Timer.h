#ifndef __TIMER__H
#define __TIMER__H

#include <chrono>
#include <cstdint>
#include <functional>
#include <thread>
namespace pjie {

using TimeEvent = std::function<void()>;
class Timer {
public:
    Timer(const TimeEvent& callback, uint64_t msec)
        : callback_(callback)
        , interval_(msec)
        , is_repeat_(false)
    {
        if (interval_ == 0) {
            interval_ = 1;
        }
    }

    static void Sleep(uint64_t msec)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(msec));
    }

    void Start(int64_t microseconds, bool repeat = false)
    {
        is_repeat_ = repeat;
        
    }

private:
    TimeEvent callback_ = [] { return false; };
    uint64_t interval_;
    uint64_t next_timeout_;
    bool is_repeat_;
};

}

#endif