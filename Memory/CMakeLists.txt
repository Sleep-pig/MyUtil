file(GLOB_RECURSE srcs CONFIGURE_DEPENDS core/*.cpp linclude/*.h)


add_library(Memory STATIC ${srcs})

target_include_directories(Memory PUBLIC include)

target_link_libraries(Memory PUBLIC Design)

