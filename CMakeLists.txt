cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0074 NEW)
set(CMAKE_CXX_STANDARD 14)

#string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
#string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
#string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

if(UNIX AND NOT APPLE)
	set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-deb/include")

endif(UNIX AND NOT APPLE)

if(WIN32)
	set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-win/include")
endif(WIN32)

#TODO: попробовать убрать лишние команды
if(WIN64)
	set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-win64/include")
	set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-win64/lib")
	set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1-win64/lib/cmake/SFML")
endif(WIN64)

include("tools/gate/cmake/HunterGate.cmake")

set(HUNTER_CACHE_SERVERS
		"https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
		CACHE STRING "Default cache server"
)

HunterGate(
		URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
		SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)

project(student-life-main)

link_directories(
        SFML_LIBRARY_DIR
)

include_directories(
        SFML_INCLUDE_DIR
)

find_package(SFML 2.5.1 COMPONENTS graphics audio system window REQUIRED)

add_executable(student-life-main Source.cpp)

target_include_directories(student-life-main
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(event_processor)

find_package(SFML 2.5.1 COMPONENTS graphics audio system window REQUIRED)

target_link_libraries(student-life-main
		sfml-graphics
		sfml-audio
		sfml-system
		sfml-window
		event_processor
)