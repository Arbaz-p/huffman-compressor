# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CompressionProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Collect all .cpp files from src/ and subdirectories
file(GLOB_RECURSE SOURCES
    "src/**/*.cpp"
)

# 🔧 Add main.cpp manually since it's outside of src/
list(APPEND SOURCES "${PROJECT_SOURCE_DIR}/main.cpp")

# Include header directories
include_directories(
    "${PROJECT_SOURCE_DIR}/header/encoding"
    "${PROJECT_SOURCE_DIR}/header/decoding"
    "${PROJECT_SOURCE_DIR}/header/compression"
)

# Create the executable
add_executable(main ${SOURCES})

# Set output directory
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
