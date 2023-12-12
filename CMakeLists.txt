#cmake_minimum_required(VERSION 3.25)
#project(2D_game_assignment)
#
#set(CMAKE_CXX_STANDARD 14)
#
#include_directories(include)
#
#configure_file(resources/background.png ${CMAKE_CURRENT_BINARY_DIR}/resources/background.png COPYONLY)
#configure_file(resources/pacman.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman.png COPYONLY)
#configure_file(resources/ghost.png ${CMAKE_CURRENT_BINARY_DIR}/resources/ghost.png COPYONLY)
#configure_file(resources/Arial.ttf ${CMAKE_CURRENT_BINARY_DIR}/resources/Arial.ttf COPYONLY)
#
#add_executable(2D_game_assignment
#        src/main.cpp
#        src/game.cpp
#        src/move.cpp
##        test/googletest.cpp
#        src/ghost.cpp
#)
#
#target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
#
## Test suite sources
#set(TEST_SOURCES
#        src/move.cpp
#        test/CoordinateTest.cpp
#        include/ghost.h
#)
#
## Add the Google Test framework
#find_package(GTest REQUIRED)
#
## Link GTest to the target
#target_link_libraries(2D_game_assignment GTest::GTest GTest::Main)
#
## Add the test executable
#add_executable(CoordinateTest ${TEST_SOURCES})
#
## Link the test executable with the main module and Google Test
#target_link_libraries(CoordinateTest PRIVATE GTest::GTest GTest::Main)
#
## Specify the executable output directory
#set_target_properties(CoordinateTest PROPERTIES
#        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test
#        )
#
## Add a test target for running tests using ctest
#add_test(NAME CoordinateTest COMMAND CoordinateTest)
#
#set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1")
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#target_link_libraries(2D_game_assignment sfml-graphics sfml-audio)
#
#
#
#
#
#
#
#
#
## Add the test executable
#add_executable(googletest ${TEST_SOURCES})
#
## Link the test executable with the main module and Google Test
#target_link_libraries(googletest PRIVATE GTest::GTest GTest::Main)
#
## Specify the executable output directory
#set_target_properties(googletest PROPERTIES
#        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test
#)
#
## Add a test target for running tests using ctest
#add_test(NAME googletest COMMAND CoordinateTest)
#
#set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1")
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#target_link_libraries(2D_game_assignment sfml-graphics sfml-audio)

cmake_minimum_required(VERSION 3.25)
project(2D_game_assignment)

set(CMAKE_CXX_STANDARD 14)

# Include FetchContent module
include(FetchContent)

include_directories(include)

# Fetch Google Test
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0  # Specify the commit, tag, or branch you want to use
)
# Make Google Test available for use
FetchContent_MakeAvailable(googletest)

# Include SFML directories
include_directories("/opt/homebrew/Cellar/sfml/2.6.1/include")
link_directories("/opt/homebrew/Cellar/sfml/2.6.1/lib")

configure_file(resources/background.png ${CMAKE_CURRENT_BINARY_DIR}/resources/background.png COPYONLY)
configure_file(resources/pacman.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman.png COPYONLY)
configure_file(resources/ghost.png ${CMAKE_CURRENT_BINARY_DIR}/resources/ghost.png COPYONLY)
configure_file(resources/Arial.ttf ${CMAKE_CURRENT_BINARY_DIR}/resources/Arial.ttf COPYONLY)

# Enable testing
enable_testing()

add_executable(2D_game_assignment
        src/main.cpp
        src/game.cpp
        src/move.cpp
        src/ghost.cpp
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Test executable
add_executable(game_tests
        test/googletest.cpp
        src/game.cpp
        src/move.cpp
        src/ghost.cpp
)

# Link Google Test and SFML to the test executable
target_link_libraries(game_tests gtest_main sfml-graphics sfml-window sfml-system)

# Add the test to be run by CTest
add_test(NAME game_tests COMMAND game_tests)