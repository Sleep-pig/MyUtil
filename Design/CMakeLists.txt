file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h core/*.cpp)

add_executable(Design  ${srcs})

target_include_directories(Design PUBLIC include)

