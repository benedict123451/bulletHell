cmake_minimum_required(VERSION 3.24)
project(NomProjet LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 23)
# Main executable

#execute_process(
#    COMMAND conan install ${CMAKE_SOURCE_DIR}/conanfile.txt
#    --build=missing
 #   -of ${CMAKE_SOURCE_DIR}/build
#)
include (build/conan_toolchain.cmake)

find_package(boost REQUIRED)
find_package(GTest REQUIRED)

enable_testing()



add_executable(main_exe main.cpp)

target_link_libraries(main_exe
PRIVATE gtest::gtest
)
