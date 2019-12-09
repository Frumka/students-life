cmake_minimum_required(VERSION 3.13)
cmake_policy(SET CMP0074 NEW)
set(CMAKE_CXX_STANDARD 14)

if(UNIX AND NOT APPLE)
	set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML/SFML-2.5.1-deb/include")

elseif(WIN32)
	set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML/SFML-2.5.1-win/include")

elseif(WIN64)
	set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML/SFML-2.5.1-win64/include")
	set(SFML_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/SFML/SFML-2.5.1-win64/lib")
	set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML/SFML-2.5.1-win64/lib/cmake/SFML")

else()
	add_subdirectory(SFML/SFML-src)

endif()

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

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(student-life-main Source.cpp)

add_executable(student-life-tests tests/Time_handler_tests.cpp tests/EventCaller_tests.cpp)

target_include_directories(student-life-main
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(student-life-tests
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

target_link_libraries(student-life-tests
		sfml-audio
		sfml-system
		GTest::main)