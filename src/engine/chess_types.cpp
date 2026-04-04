#include "chess_types.hpp"
std::string ToString(const ChessColor_T& color)
{
	std::string strResult;
	switch (color)
	{
	case ChessColor_T::NONE_SIDE:
	{
		strResult = "NONE_SIDE";
	}break;
	case ChessColor_T::BLACK_SIDE:
	{
		strResult = "BLACK_SIDE";
	}break;
	case ChessColor_T::RED_SIDE:
	{
		strResult = "RED_SIDE";
	}break;
	default: 
	{
		strResult = "NONE_SIDE";
	}break;
	}
	return strResult;
}

std::string ToString(const ChessMan_T& type)
{
	std::string strResult;
	switch (type)
	{
	case ChessMan_T::ROOK_MAN:
	{
		strResult = "ROOK";
	}break;
	case ChessMan_T::KNIGHT_MAN:
	{
		strResult = "KNIGHT";
	}break;
	case ChessMan_T::BISHOP_MAN:
	{
		strResult = "BISHOP";
	}break;
	case ChessMan_T::QUEEN_MAN:
	{
		strResult = "QUEEN";
	}break;
	case ChessMan_T::KING_MAN:
	{
		strResult = "KING";
	}break;
	case ChessMan_T::CANNON_MAN:
	{
		strResult = "CANNON";
	}break;
	case ChessMan_T::PAWN_MAN:
	{
		strResult = "PAWN";
	}break;
	default:
	{
		strResult = "NONE";
	}break;

	}
	return strResult;
}

std::string ToString(const ChessBoardElem_T & elem)
{
	std::string strResult;
	strResult = ToString(elem._color);
	strResult += " ";
	strResult +=ToString(elem._manType);
	return strResult;
}
std::string ToString(const ChessGrid_T& grid)
{
	std::string strResult;
	strResult = "(" + std::to_string(grid._gridX) + "," + std::to_string(grid._gridY)+")";
	return strResult;
}

std::string ToString(const ChessMove_T& move)
{
	std::string strResult;
	strResult += ToString(move._chessMan);
	strResult += "  ";
	strResult += ToString(move._fromGrid);
	strResult += "--->";
	strResult += ToString(move._toGrid);
	return strResult;
}