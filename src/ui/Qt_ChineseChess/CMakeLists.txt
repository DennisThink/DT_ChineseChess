# Minimum CMake version required
cmake_minimum_required(VERSION 3.16)

# Project name and version
project(QtChineseChess VERSION 1.0.0 LANGUAGES CXX)
include_directories(../../engine/)
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)  # Enable automatic MOC for Qt signals/slots
set(CMAKE_AUTOUIC ON)  # Enable automatic UIC for Qt UI files
set(CMAKE_AUTORCC ON)  # Enable automatic RCC for Qt resources

set(Qt6_DIR "F:\\Qt\\6.11.0\\msvc2022_64\\lib\\cmake\\Qt6")
# Find Qt6 or Qt5
find_package(Qt6 REQUIRED COMPONENTS Widgets)
# If using Qt5 instead, replace with:
# find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Add executable
add_executable(${PROJECT_NAME}
    main.cpp
    dialog.h
    dialog.cpp
    QPixmapManager.h
    QPixmapManager.cpp
    ../../engine/ChessBoard.hpp
    ../../engine/ChessBoard.cpp
)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME}
    Qt6::Widgets  # Or Qt5::Widgets
)

# Set properties (optional)
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE  # On Windows, create a GUI app without console
)