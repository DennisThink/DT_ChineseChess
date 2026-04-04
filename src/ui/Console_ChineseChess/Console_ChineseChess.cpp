#include <iostream>
#include "ChessNotation.hpp"
#include <windows.h>
#include <fcntl.h>
#include <io.h>
int main(int argc, char* argv[])
{
	//SetConsoleOutputCP(CP_UTF8);
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << "Console_ChineseChess" << std::endl;

	ChessNotation chessNotation;
	if(chessNotation.LoadFromFile("F:\\Github\\DT_ChineseChess\\src\\ui\\notations_sample\\pgn_sample_1.pgn"))
	{
		std::wcout << "Load PGN file successfully." << std::endl;
		chessNotation.PrintPGNNotation();
	}
	else
	{
		std::wcout << "Failed to load PGN file." << std::endl;
	}
	int x = 0;
	std::wcin >> x;
	return 0;
}