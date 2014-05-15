cmake_minimum_required(VERSION 2.8.4)
project(bigprojecttest)


# Global settings
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)


# 3rdparty Libraries
include(CMakeLists-ExternalProjects.txt)


# Global compiler flags
# -std=c++11  =>  Used by HumbleLogging
set(CMAKE_CXX_FLAGS -std=c++11)


# Global link directories
link_directories(${PROJECT_BINARY_DIR}/bin)


# Libraries (+ their includes)
add_subdirectory(src/lib1)
include_directories(src/lib1/include)

add_subdirectory(src/lib2)
include_directories(src/lib2/include)


# Applications
add_subdirectory(src/app1)
add_subdirectory(src/app2)


# Installation
# Copies files from build directory into install directory.
file(GLOB executables "${PROJECT_BINARY_DIR}/bin/*.exe")
install(FILES ${executables} DESTINATION "bin")

file(GLOB libraries "${PROJECT_BINARY_DIR}/bin/*.dll")
install(FILES ${libraries} DESTINATION "bin")


# SDK Installation
install(DIRECTORY "src/lib1/include/" DESTINATION "include" FILES_MATCHING PATTERN "*.h")
install(DIRECTORY "src/lib2/include/" DESTINATION "include" FILES_MATCHING PATTERN "*.h")




# DEV STUFF
#
#install(TARGETS lib1 lib2 app1 app2
#  RUNTIME DESTINATION ${INSTALL_PATH}/bin
#  LIBRARY DESTINATION ${INSTALL_PATH}/bin
#  ARCHIVE DESTINATION ${INSTALL_PATH}/bin
#)