#ifndef __JOIN_THREAD__H
#define __JOIN_THREAD__H

#include <thread>
#include <utility>
namespace pjie {

class join_thread {
private:
    std::thread t_;

public:
    join_thread() noexcept = default;
    // join_thread(join_thread const&) = delete;
    template <typename Callable, typename... Args>
    explicit join_thread(Callable&& callable, Args&&... args) noexcept
        : t_(std::forward<Callable>(callable), std::forward<Args>(args)...)
    {
    }
    explicit join_thread(std::thread t) noexcept
        : t_(std::move(t))
    {
    }

    explicit join_thread(join_thread&& other) noexcept
        : t_(std::move(other.t_))
    {
    }

    join_thread& operator=(join_thread&& other) noexcept
    {
        if (Joinable()) {
            Join();
        }
        t_ = std::move(other.t_);
        return *this;
    }

    join_thread& operator=(std::thread&& t) noexcept
    {
        if (Joinable()) {
            Join();
        }
        t_ = std::move(t);
        return *this;
    }

    ~join_thread()
    {
        if (Joinable()) {
            Join();
        }
    }

    void Swap(join_thread& other) noexcept
    {
        t_.swap(other.t_);
    }

    std::thread::id GetId() noexcept
    {
        return t_.get_id();
    }

    std::thread& Asthread() noexcept
    {
        return t_;
    }

    const std::thread& Asthtread() const noexcept
    {
        return t_;
    }

    bool Joinable() noexcept
    {
        return t_.joinable();
    }

    void Join() noexcept
    {
        t_.join();
    }

    void Detach() noexcept
    {
        t_.detach();
    }
};

}

#endif
