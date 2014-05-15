# lib2
include_directories(include)
file(GLOB lib2_headers include/lib2/*.h)
file(GLOB lib2_sources src/*.cpp)
add_library(lib2 SHARED ${lib2_headers} ${lib2_sources})