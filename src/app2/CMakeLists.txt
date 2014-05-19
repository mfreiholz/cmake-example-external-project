# app2
file(GLOB app2_sources src/*.cpp)
add_executable(app2 ${app2_sources})
target_link_libraries(app2 lib2)