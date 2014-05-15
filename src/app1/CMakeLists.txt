# app1
file(GLOB app1_sources src/*.cpp)
add_executable(app1 ${app1_sources})
target_link_libraries(app1 lib1)