file(GLOB_RECURSE srcs CMAKE_CONFIGURE_DEPENDS core/*.cpp include/*.h)


add_library(TimeStamp STATIC ${srcs})

target_include_directories(TimeStamp PUBLIC include)