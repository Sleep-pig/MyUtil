file(GLOB_RECURSE srcs CONFIGURE_DEPENDS include/*.h core/*.cpp)

add_library(Design STATIC ${srcs})

target_include_directories(Design PUBLIC include)

