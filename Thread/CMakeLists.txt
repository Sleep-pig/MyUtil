file(GLOB_RECURSE srcs CONFIGURE_DEPENDS core/*.cpp include/*.cpp)



add_executable(text_thread ${srcs})

target_include_directories(text_thread PUBLIC include)
