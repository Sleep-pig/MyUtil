file(GLOB_RECURSE srcs CONFIGURE_DEPENDS core/*.cpp include/*.h)


add_executable(text_MessageNode ${srcs})

target_link_libraries(text_MessageNode PUBLIC Design)
target_include_directories(text_MessageNode PUBLIC include)
