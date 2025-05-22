#include <Memory/MemoryManger.h>
#include <cstdlib>
#include <mutex>

namespace pjie {

static void* Alloc(uint32_t size)
{
    return MemoryManger::GetInstance()->Alloc(size);
}

static void Free(void* ptr)
{
    MemoryManger::GetInstance()->Free(ptr);
}

MemoryPool::MemoryPool()
    : head(nullptr)
    , memory(nullptr)
{
}
MemoryPool::~MemoryPool()
{
    if (memory) {
        ::free(memory);
    }
}

void MemoryPool::Init(uint32_t block_size_, uint32_t block_num_)
{
    memory = (char*)malloc(block_num_ * (block_size_ + sizeof(MemoryBlock)));
    head = (MemoryBlock*)memory;
    head->block_id = 1;
    head->next = nullptr;
    head->pool = this;

    MemoryBlock* current = head;
    for (int i = 1; i < block_num_; i++) {
        auto next = (MemoryBlock*)(memory + i * (sizeof(MemoryBlock) + block_size_));
        next->block_id = i + 1;
        next->next = nullptr;
        next->pool = this;
        current->next = next;
        current = next;
    }
}

void* MemoryPool::Alloc(uint32_t size_)
{
    std::lock_guard<std::mutex> lk(mtx_);
    if (head != nullptr) {
        auto block = head;
        head = head->next;
        return ((char*)block + sizeof(MemoryBlock));
    }
    return nullptr;
}
void MemoryPool::Free(void* ptr)
{
    auto block = (MemoryBlock*)((char*)(ptr) - sizeof(MemoryBlock));
    if (block->block_id != 0) {
        std::lock_guard<std::mutex> lk(mtx_);
        block->next = head;
        head = block;
    }
}
MemoryManger::MemoryManger()
{
    memory_pools_[0].Init(4096, 50); // 4M * 50
    memory_pools_[1].Init(40960, 10); // 40M * 10
    memory_pools_[2].Init(102400, 5); // 100M * 5
}
MemoryManger::~MemoryManger()
{
}
void* MemoryManger::Alloc(uint32_t size)
{
    for (int n = 0; n < kMaxMemoryPool; n++) {
        if (size <= memory_pools_[n].BlockSize()) {
            void* ptr = memory_pools_[n].Alloc(size);
            if (ptr != nullptr) {
                return ptr;
            } else {
                break;
            }
        }
    }

    MemoryBlock* block = (MemoryBlock*)malloc(size + sizeof(MemoryBlock));
    block->block_id = 0;
    block->pool = nullptr;
    block->next = nullptr;
    return ((char*)block + sizeof(MemoryBlock));
}
void MemoryManger::Free(void* ptr)
{
    MemoryBlock* block = (MemoryBlock*)((char*)ptr - sizeof(MemoryBlock));
    MemoryPool* pool = block->pool;

    if (pool != nullptr && block->block_id > 0) {
        pool->Free(ptr);
    } else {
        ::free(block);
    }
}

}