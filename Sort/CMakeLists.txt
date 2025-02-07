file(GLOB_RECURSE srcs CMAKE_CONFIGURE_DEPENDS core/*.cpp include/*.h)


add_executable(Sort ${srcs})

target_include_directories(Sort PUBLIC include)