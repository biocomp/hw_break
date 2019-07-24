# CMakeList.txt : CMake project for HwBpLib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library(HwBpLib "src/HwBpLib.cpp" "inc/HwBpLib.h")
target_include_directories(HwBpLib PRIVATE "./inc")

enable_testing()

add_executable(HwBpTest "test/test.cpp")
target_link_libraries(HwBpTest PRIVATE HwBpLib)
target_include_directories(HwBpTest PRIVATE "./inc")

add_test(NAME TestHwBp COMMAND HwBpTest)
