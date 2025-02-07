#include "Thread/join_thread.h"
#include <chrono>
#include <iostream>
#include <thread>
using namespace pjie;

int main()
{
    join_thread mythread([](int a, int b) {
        for (int i = 0; i < 10; i++) {
            std::cout << "thread id:" << std::this_thread::get_id() << "  a+b:" << a + b << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    },
        10, 2);

    auto func = []() {
        for (int i = 0; i < 10; i++) {
            std::cout << "thread id:" << std::this_thread::get_id() << "sleep 1s\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    };

    join_thread t1(std::move(mythread));
}