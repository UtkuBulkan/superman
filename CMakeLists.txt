cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
set(SOURCES manager/Manager.cpp camera/Camera.cpp camera/CameraManager.cpp)

#For the shared library:
set ( PROJECT_LINK_LIBS libopencv_core.so )

include_directories(/usr/local/include/opencv ./camera)

link_directories( /usr/locl/lib )

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "manager/Manager.cpp" "camera/*.cpp" "camera/*.h")

add_executable(Manager ${SOURCES})
