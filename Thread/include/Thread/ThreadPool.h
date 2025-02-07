#ifndef __THREADPOOL__H
#define __THREADPOOL__H

#include <atomic>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>
namespace pjie {

class ThreadPool {
public:
    using Task = std::packaged_task<void()>;

    ThreadPool(ThreadPool const&) = delete;
    ThreadPool& operator=(ThreadPool const&) = delete;
    static ThreadPool& GetInstance(int thread_num = 0)
    {
        static ThreadPool ins(thread_num);
        return ins;
    }

    template <typename F, typename... Args>
    auto commit(F&& func, Args&&... args) -> std::future<decltype(func(args...))>
    {
        using RetType = decltype(func(args...));
        if (stop_.load()) {
            return std::future<RetType> {};
        }
        auto task = std::make_shared<std::packaged_task<RetType()>>(
            std::bind(std::forward<F>(func), std::forward<Args>(args)...));
        std::future<RetType> ret = task->get_future();
        {
            std::lock_guard<std::mutex> lk(mtx_);
            tasks_.emplace([task]() -> void { (*task)(); });
        }
        cond_.notify_one();
        return ret;
    }

    int ThreadNum()
    {
        return thread_num_;
    }

    ~ThreadPool()
    {
        stop();
    }

private:
    ThreadPool(unsigned int num = std::thread::hardware_concurrency())
        : stop_(false)
    {
        if (num < 1) {
            thread_num_ = 1;
        } else {
            thread_num_ = num;
        }
    }

    void Start()
    {
        for (unsigned int i = 0; i < thread_num_; ++i) {
            pool_.emplace_back([this]() {
                while (!stop_.load()) {
                    Task task;
                    {
                        std::unique_lock<std::mutex> cv_mt_(mtx_);
                        cond_.wait(cv_mt_, [this]() {
                            return stop_.load() || !tasks_.empty();
                        });
                        if (tasks_.empty()) {
                            return;
                        }
                        task = std::move(tasks_.front());
                        tasks_.pop();
                    }
                    thread_num_--;
                    task();
                    thread_num_++;
                }
            });
        }
    }

    void stop()
    {
        stop_.store(true);
        cond_.notify_all();
        for (auto& t : pool_) {
            if (t.joinable()) {
                std::cout << "join thread:" << t.get_id() << std::endl;
                t.join();
            }
        }
    }

    std::mutex mtx_;
    std::condition_variable cond_;
    std::atomic_bool stop_;
    std::atomic_int thread_num_;
    std::queue<Task> tasks_;
    std::vector<std::thread> pool_;
};

}

#endif