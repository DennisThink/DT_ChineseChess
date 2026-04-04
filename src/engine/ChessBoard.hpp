#ifndef _DT_CHINESE_CHESS_BOARD_
#define _DT_CHINESE_CHESS_BOARD_
#include "chess_types.hpp"
#include <vector>

class ChessBoard
{
public:
    ChessBoard();
    void printBoard();
    int GetMaxX() const;
    int GetMaxY() const;
    void SetBoardToStartState();
    const ChineseBoardData_T& GetBoardData();
    const ChessBoardElem_T& GetGridChess(const ChessGrid_T& grid)const;
    bool OnMove(const ChessMove_T& moveAct);
    bool IsGoodSelectedGrid(const ChessGrid_T& grid) const;
    bool IsGoodTargetGrid(const ChessGrid_T& origGrid, const ChessGrid_T& targetGrid) const;
    bool IsGridInBoard(const ChessGrid_T& grid) const;
    bool IsChessInGrid(const ChessGrid_T& grid, const ChessBoardElem_T& chess)const;
    bool SwapSide();
	std::vector<ChessGrid_T> GetMoveableGrids(const ChessGrid_T& curGrid)const;
	std::vector<ChessGrid_T> GetChessGrids(const ChessBoardElem_T& side) const;
	bool IsSideInCheck(ChessColor_T side) const;
	std::vector<ChessMove_T> GetAllCheckMoves(ChessColor_T side) const;
    bool SetBoardData(const ChineseBoardData_T& boardData);
private:
	bool CanMove(const ChessMove_T& moveAct) const;
    bool CanRookMove(const ChessMove_T& moveAct) const;
	bool CanKnightMove(const ChessMove_T& moveAct) const;
	bool CanBishopMove(const ChessMove_T& moveAct) const;
	bool CanQueenMove(const ChessMove_T& moveAct) const;
	bool CanKingMove(const ChessMove_T& moveAct) const;
	bool CanCannonMove(const ChessMove_T& moveAct) const;
	bool CanPawnMove(const ChessMove_T& moveAct) const;
    

    int GetRedKingIndex();
	int GetBlackKingIndex();
    int m_RedKingIndex;
	int m_BlackKingIndex;
    ChineseBoardData_T m_board;
    int _X_MAX_GRID;
    int _Y_MAX_GRID;
};
#endif