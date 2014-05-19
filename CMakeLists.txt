cmake_minimum_required(VERSION 2.8.4)
project(bigprojecttest)


# Global settings
set(GLOBAL_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)

# Sets global output directory for single configuration (GCC)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${GLOBAL_OUTPUT_PATH})

# Sets global output directory for sub-configurations (msvc, mingw)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${GLOBAL_OUTPUT_PATH})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${GLOBAL_OUTPUT_PATH})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${GLOBAL_OUTPUT_PATH})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)


# 3rdparty Libraries
include(CMakeLists-ExternalProjects.txt)


# Global compiler flags
# -std=c++11  =>  Used by HumbleLogging
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS -std=c++11)
else()
  add_definitions(-DWIN32) # TMP
endif()


# Global link directories
link_directories(${GLOBAL_OUTPUT_PATH})


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
file(GLOB executables "${GLOBAL_OUTPUT_PATH}/*.exe")
install(FILES ${executables} DESTINATION "bin")

file(GLOB libraries "${GLOBAL_OUTPUT_PATH}/*.dll")
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