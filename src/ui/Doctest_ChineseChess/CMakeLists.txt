cmake_minimum_required(VERSION 3.0)
project(Doctest_ChineseChess)
include_directories(./inc/doctest/)
include_directories(../../engine/)
SET(SOURCE_FILE ./main.cpp ./ChessNotation_test.cpp
../../engine/ChessNotation.cpp
../../engine/ChessBoard.cpp
../../engine/chess_types.cpp)
add_executable(Doctest_Chinese ${SOURCE_FILE})