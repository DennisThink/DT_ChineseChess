cmake_minimum_required(VERSION 3.0)
project(DT_ChineseChess)
include_directories(../../engine/)
SET(SOURCE_FILE Console_ChineseChess.cpp 
../../engine/ChessBoard.cpp
../../engine/ChessNotation.cpp
../../engine/chess_types.cpp)
add_executable(Console_ChineseChess ${SOURCE_FILE})