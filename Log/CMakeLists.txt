file(GLOB_RECURSE srcs CONFIGURE_DEPENDS core/*.cpp include/*.h)

add_executable(text_log ${srcs})

target_include_directories(text_log PUBLIC include)

target_link_libraries(text_log PUBLIC TimeStamp)