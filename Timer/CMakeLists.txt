file(GLOB_RECURSE srcs CMAKE_CONFIGURE_DEPENDS core/*.cpp include/*.h)


add_library(Timer STATIC ${srcs})

target_include_directories(Timer PUBLIC include)

