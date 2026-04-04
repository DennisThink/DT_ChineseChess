#ifndef CHESS_NOTATION_HPP
#define CHESS_NOTATION_HPP

#include "chess_types.hpp"
#include "TextFileReader.hpp"
#include "ChessBoard.hpp"
#include <string>
#include <vector>

enum NotationPosition_T
{
	NONE_POSITION = -1,
	FRONT_POSITION = 0,//前
	MIDDLE_POSITION = 1,//中
	BACK_POSITION = 2,//后
};

enum MoveDirection_T
{
	NONE_DIRECTION = -1,
	FORWARD_DIRECTION = 0,//进
	BACK_DIRECTION = 1,//退
	HORIZON_DIRECTION = 2,//平
};
struct NotationMoveAct_T
{
	NotationPosition_T m_pos;
	ChessBoardElem_T m_chessMan;
	int m_fromNumber;
	MoveDirection_T m_moveDirection;
	int	m_toNumber;
};

struct NotationMove_T
{
	std::wstring m_strMoveNotation;
	NotationMoveAct_T m_notationMoveAct;
	ChessMove_T m_chessBoardMoveAct;
};
struct ChessMoveNotation_T
{
	std::wstring m_strRoundMoveNotation;
	NotationMove_T m_redMove;
	NotationMove_T m_blackMove;
};

struct PGN_Notation_T
{
	std::wstring m_strGame;
	std::wstring m_strEvent;
	std::wstring m_strRound;
	std::wstring m_strDate;
	std::wstring m_strSite;
	std::wstring m_strRed;
	std::wstring m_strRedTeam;
	std::wstring m_strBlack;
	std::wstring m_strBlackTeam;
	std::wstring m_strResult;
	std::wstring m_strECCO;
	std::wstring m_strFEN;
	std::wstring m_strComment;
	std::vector<ChessMoveNotation_T> m_strMoveVec;
};

class ChessNotation 
{
public:
	ChessNotation();
	bool LoadFromFile(const char* filePath);
	bool SaveToFile(const char* filePath) const;
	bool OnPrevMove();
	bool OnNextMove();
	const ChineseBoardData_T& GetChessBoardData() const;
	void PrintPGNNotation() const;
	ChessMoveNotation_T ParseMoveNotation(const std::wstring& moveNotation);
	NotationMoveAct_T ParseNotationMoveAct(const std::wstring& moveActStr, const ChessColor_T& color);
	ChessMove_T ParseNotationMoveActToChessMove(const NotationMoveAct_T& notationMoveAct);
	ChessMove_T ParseMoveAct(const std::wstring& moveActStr);
	int WStringToNumber(const std::wstring w) const;
	bool ParsePGN(const char* filePath);
	ChessMan_T WStringToChessMan(const std::wstring& w) const;
	NotationPosition_T ParsePosition(const std::wstring& w) const;
	MoveDirection_T ParseDirection(const std::wstring& w) const;
	ChessMove_T ParseMoveAct(const NotationMoveAct_T& notaMove);
private:
	PGN_Notation_T m_pgnNotation;
	ChessBoard m_chessBoard;

	ChineseBoardData_T m_boardPrevData;
	ChineseBoardData_T m_boardCurData;
	ChineseBoardData_T m_boardNextData;
};
std::string ToString(const MoveDirection_T& color);
std::string ToString(const NotationMoveAct_T& moveAct);
#endif