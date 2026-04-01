cmake_minimum_required(VERSION 3.0)
project(DT_ChineseChess)
include_directories(../../engine/)
SET(SOURCE_FILE main.cpp 
../../engine/ChessBoard.cpp 
./UI_ChessBoard.cpp 
./UI_ImageManager.cpp 
./UI_ChessButton.cpp)
add_executable(EasyX_ChineseChess ${SOURCE_FILE})