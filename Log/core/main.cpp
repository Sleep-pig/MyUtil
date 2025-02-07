#include <Log/AsyncLog.h>
#include <Log/logger.h>

int main()
{
    // auto& inst = AsyncLog::getInstance();
    // inst.AsyncWrite(ERRORS, "nihao age:{},name:{}",10,"jie");
    // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    LOG_DEBUG("nihao %d,woshi%s",10,"pjei");
    return 0;
}