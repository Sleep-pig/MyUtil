#ifndef __MEMORYMANGER__H
#define __MEMORYMANGER__H

#include <Design/SingleTon.h>
#include <cstddef>
#include <cstdint>
#include <mutex>

namespace pjie {


class MemoryPool;



struct MemoryBlock {
    uint32_t block_id = 0;
    MemoryBlock* next = nullptr;
    MemoryPool* pool = nullptr;
};

class MemoryPool {

public:
    MemoryPool();
    ~MemoryPool();
    void Init(uint32_t block_size_, uint32_t block_num_);

    void* Alloc(uint32_t size_);
    void Free(void* ptr);

    size_t BlockSize() const
    {
        return block_size;
    }
    std::mutex mtx_;
    char* memory;
    uint32_t block_num;
    uint32_t block_size;
    MemoryBlock* head;
};

class MemoryManger : public Singleton<MemoryManger> {
    friend class Singleton<MemoryManger>;

public:
    ~MemoryManger();
    void* Alloc(uint32_t size);
    void Free(void* ptr);

private:
    MemoryManger();
    static const int kMaxMemoryPool = 3;
    MemoryPool memory_pools_[kMaxMemoryPool];
};

}

#endif