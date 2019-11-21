cmake_minimum_required(VERSION 3.13)
project(sfml_playground)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-deb/include")
set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-deb/lib")
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-deb/lib/cmake/SFML")

#message("DIR: [${CMAKE_SOURCE_DIR}] \n PATH: [${CMAKE_MODULE_PATH}] \n SFML_DIR:[${SFML_DIR}]")

link_directories(
        SFML_LIBRARY_DIR
)

include_directories(
        SFML_INCLUDE_DIR
)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}" ${CMAKE_MODULE_PATH})
#set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules")
find_package(SFML 2.5.1 COMPONENTS graphics audio system window REQUIRED)

add_executable(sfml_playground Source.cpp)

target_link_libraries(sfml_playground sfml-graphics sfml-audio sfml-system sfml-window)