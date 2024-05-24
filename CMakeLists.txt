#Command to compile without Neovim errors ! :
#cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS_ON

cmake_minimum_required(VERSION 3.0)
project(GraphCalc)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find wxWidgets package
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add include directories for wxWidgets
include_directories(${wxWidgets_INCLUDE_DIRS})

# Add your source files
set(SOURCES
    src/main.cpp
    src/frame.cpp
    src/draw.cpp
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against wxWidgets libraries
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
