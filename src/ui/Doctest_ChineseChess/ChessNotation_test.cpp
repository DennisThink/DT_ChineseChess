#include "doctest.h"
#include "ChessNotation.hpp"
#include "ChessBoard.hpp"
TEST_CASE("ChessNotation") 
{
	ChessNotation notation;
	std::string filePath = "F:\\Github\\DT_ChineseChess\\src\\ui\\notations_sample\\pgn_sample_1.pgn";
	CHECK(notation.LoadFromFile(filePath.c_str()) == true);
	{
		std::wstring notationStr = L" 13. 相七进五 马３进４";
		auto notationMove = notation.ParseMoveNotation(notationStr);
		bool bNotation = notationMove.m_strRoundMoveNotation == notationStr;
		CHECK(bNotation);
		{
			std::wstring expectedRedMoveNotation = L"相七进五";
			bool bRed = notationMove.m_redMove.m_strMoveNotation == expectedRedMoveNotation;
			CHECK(bRed);
			std::wstring expectedBlackMoveNotation = L"马３进４";
			bool bBlack = notationMove.m_blackMove.m_strMoveNotation == expectedBlackMoveNotation;
			CHECK(bBlack);
		}
	}
}