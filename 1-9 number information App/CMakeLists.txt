cmake_minimum_required(VERSION 3.10)
project(NumberInformationApp VERSION 2.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags for better warnings and optimization
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Source files
set(SOURCES
    main.cpp
    NumberDatabase.cpp
    QuizEngine.cpp
    UI.cpp
)

# Header files
set(HEADERS
    NumberInfo.h
    NumberDatabase.h
    QuizEngine.h
    UI.h
)

# Create executable
add_executable(number_info_app ${SOURCES} ${HEADERS})

# Set output directory
set_target_properties(number_info_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Installation rules
install(TARGETS number_info_app
    RUNTIME DESTINATION bin
)

# Print build information
message(STATUS "Building 1-9 Number Information App v${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
