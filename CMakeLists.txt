cmake_minimum_required(VERSION 3.24)
project(NomProjet LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 23)
# Main executable

#execute_process(
#    COMMAND conan install ${CMAKE_SOURCE_DIR}/conanfile.txt
#    --build=missing
 #   -of ${CMAKE_SOURCE_DIR}/build
#)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/assets
DESTINATION .
FILES_MATCHING
PATTERN "*.*")

add_custom_target(copy_assets_to_runtime ALL
COMMAND ${CMAKE_COMMAND} --install . --prefix
${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/release
COMMENT "Installing assets to runtime directory"
)
include (build/conan_toolchain.cmake)

find_package(boost REQUIRED)
find_package(GTest REQUIRED)
find_package(SFML 2.6 REQUIRED COMPONENTS system window graphics)

enable_testing()

add_subdirectory(src)




