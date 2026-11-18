add_executable(test
    Src/main.c
)

target_include_directories(test PRIVATE Inc)

set(BUILD_SHARED_LIBS ON)
CPMAddPackage("gh:MaJerle/lwprintf#v1.1.0")
unset(BUILD_SHARED_LIBS)

target_link_libraries(test PRIVATE lwprintf)

target_link_libraries(test PRIVATE sys_SHARED sys_STATIC)
