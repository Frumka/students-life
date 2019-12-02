cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
        SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)

project(event_processor)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(tests
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
        )

add_library(event_processor STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/source.cpp
        )

target_include_directories(event_processor
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
target_include_directories(tests
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

set_target_properties(event_processor PROPERTIES
        VERSION 2
        SOVERSION 0
        PUBLIC_HEADER include/event_processor.hpp)

target_link_libraries(tests GTest::main nlohmann_json::nlohmann_json)
target_link_libraries(event_processor nlohmann_json::nlohmann_json)
