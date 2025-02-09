#ifndef __SINGLETON__H
#define __SINGLETON__H

#include <memory>
#include <mutex>
namespace pjie {

template <typename T>

class Singleton {
protected:
    Singleton() = default;
    Singleton(Singleton<T> const&) = delete;
    Singleton& operator=(const Singleton<T>&) = delete;
    static std::shared_ptr<T> _instance;

public:
    static std::shared_ptr<T>& GetInstance()
    {
        static std::once_flag _once;   //保证线程安全
        std::call_once(_once, [&]() {
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }
    ~Singleton(){}
};


template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;  //懒汉式

}

#endif