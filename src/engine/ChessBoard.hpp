#ifndef _DT_CHINESE_CHESS_BOARD_
#define _DT_CHINESE_CHESS_BOARD_
#include "chess_types.hpp"
struct ChineseBoardData_T
{
    ChessManBoardElem _board[9][10];
};
class ChessBoard
{
public:
    ChessBoard();
    void printBoard();
    int GetMaxX() const;
    int GetMaxY() const;
    void SetBoardToStartState();
    const ChineseBoardData_T& GetBoardData();
    const ChessManBoardElem& GetGridChess(const ChessGrid_T& grid);
    bool OnMove(const ChessMove_T& moveAct);
    bool IsGoodSelectedGrid(const ChessGrid_T& grid);
    bool IsGoodTargetGrid(const ChessGrid_T& origGrid, const ChessGrid_T& targetGrid);
    bool IsGridInBoard(const ChessGrid_T& grid);
    bool IsChessInGrid(const ChessGrid_T& grid, const ChessManBoardElem& chess);
    bool SwapSide();
private:
	bool OnRookMove(const ChessMove_T& moveAct);
	bool OnKnightMove(const ChessMove_T& moveAct);
	bool OnBishopMove(const ChessMove_T& moveAct);
	bool OnQueenMove(const ChessMove_T& moveAct);
	bool OnKingMove(const ChessMove_T& moveAct);
	bool OnCannonMove(const ChessMove_T& moveAct);
	bool OnPawnMove(const ChessMove_T& moveAct);

    int GetRedKingIndex();
	int GetBlackKingIndex();
    int m_RedKingIndex;
	int m_BlackKingIndex;
    ChineseBoardData_T m_board;
    int _X_MAX_GRID;
    int _Y_MAX_GRID;
};
#endif