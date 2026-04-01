cmake_minimum_required(VERSION 3.16)
# Project name and version
project(MFC_ChineseChess VERSION 1.0.0 LANGUAGES CXX)
set(USE_UNICODE ON)
include_directories(../../engine/)
set(SOURCES
    main.cpp
    ChessDialog.cpp
    CImageManager.cpp
    ../../engine/ChessBoard.cpp
)

set(HEADERS
    ChessDialog.h)


add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${HEADERS})
target_compile_definitions(${PROJECT_NAME} PRIVATE _AFXDLL)
#set_property(TARGET ${PROJECT_NAME} PROPERTY MFC "dynamic")