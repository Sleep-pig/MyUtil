#ifndef __TIMESTAMP__H
#define __TIMESTAMP__H

#include <chrono>
#include <cstdint>
#include <string>

namespace pjie {
class Timestamp {
public:
    Timestamp()
        : begin_time_point(std::chrono::high_resolution_clock::now())
    {
    }

    void Reset()
    {
        begin_time_point = std::chrono::high_resolution_clock::now();
    }

    int64_t Elapsed()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - begin_time_point).count();
    }

    static std::string Localtime();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> begin_time_point;
};

}

#endif