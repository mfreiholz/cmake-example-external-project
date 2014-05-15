# lib1
include_directories(include)
file(GLOB lib1_headers include/lib1/*.h)
file(GLOB lib1_sources src/*.cpp)
add_library(lib1 SHARED ${lib1_headers} ${lib1_sources})

# Link against external project "humblelogging"
target_link_libraries(lib1 ${HumbleLogging_LIBRARIES})
add_dependencies(lib1 HumbleLogging)