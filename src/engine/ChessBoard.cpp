#include "ChessBoard.hpp"
#include <iostream>
void ChessBoard::printBoard()
{
    int cellWidth=2;

    int BOARD_WIDTH =8;
    int BOARD_HEIGHT=8;
    for(int i = 0 ; i < BOARD_HEIGHT ; i++)
    {
        {
            for (int j = 0; j < BOARD_WIDTH;j++)
            {
                for (int k = 0; k < cellWidth; k++)
                {
                    std::cout << "--"; //std::endl;
                }
            }
            std::cout << "\r\n" << std::endl;
        }
        {
            for (int j = 0; j < BOARD_WIDTH;j++)
            {
                std::cout << "|";
                for (int k = 0; k < cellWidth; k++)
                {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\r\n" << std::endl;
    }
}

    int ChessBoard::GetMaxX() const
    {
        return _X_MAX_GRID;
    }
    int ChessBoard::GetMaxY() const
    {
        return _Y_MAX_GRID;
    }
    void ChessBoard::SetBoardToStartState()
    {
        auto& _board = m_board._board;
        int maxX = GetMaxX();
        int maxY = GetMaxY();
        for (int x = 0; x < maxX; x++)
        {
            for (int y = 0; y < maxY; y++)
            {
                _board[x][y]._color = ChessColor_T::NONE_SIDE;
                _board[x][y]._manType = ChessMan_T::NONE_MAN;
            }
        }
        m_RedKingIndex = 0;
        m_BlackKingIndex = 9;
        //RED SIDE
        _board[0][0]._color = ChessColor_T::RED_SIDE;
        _board[0][0]._manType = ChessMan_T::ROOK_MAN;

        _board[1][0]._color = ChessColor_T::RED_SIDE;
        _board[1][0]._manType = ChessMan_T::KNIGHT_MAN;

        _board[2][0]._color = ChessColor_T::RED_SIDE;
        _board[2][0]._manType = ChessMan_T::BISHOP_MAN;

        _board[3][0]._color = ChessColor_T::RED_SIDE;
        _board[3][0]._manType = ChessMan_T::QUEEN_MAN;

        _board[4][0]._color = ChessColor_T::RED_SIDE;
        _board[4][0]._manType = ChessMan_T::KING_MAN;

        _board[5][0]._color = ChessColor_T::RED_SIDE;
        _board[5][0]._manType = ChessMan_T::QUEEN_MAN;

        _board[6][0]._color = ChessColor_T::RED_SIDE;
        _board[6][0]._manType = ChessMan_T::BISHOP_MAN;

        _board[7][0]._color = ChessColor_T::RED_SIDE;
        _board[7][0]._manType = ChessMan_T::KNIGHT_MAN;

        _board[8][0]._color = ChessColor_T::RED_SIDE;
        _board[8][0]._manType = ChessMan_T::ROOK_MAN;


        _board[1][2]._color = ChessColor_T::RED_SIDE;
        _board[1][2]._manType = ChessMan_T::CANNON_MAN;

        _board[7][2]._color = ChessColor_T::RED_SIDE;
        _board[7][2]._manType = ChessMan_T::CANNON_MAN;

        _board[0][3]._color = ChessColor_T::RED_SIDE;
        _board[0][3]._manType = ChessMan_T::PAWN_MAN;

        _board[2][3]._color = ChessColor_T::RED_SIDE;
        _board[2][3]._manType = ChessMan_T::PAWN_MAN;

        _board[4][3]._color = ChessColor_T::RED_SIDE;
        _board[4][3]._manType = ChessMan_T::PAWN_MAN;

        _board[6][3]._color = ChessColor_T::RED_SIDE;
        _board[6][3]._manType = ChessMan_T::PAWN_MAN;

        _board[8][3]._color = ChessColor_T::RED_SIDE;
        _board[8][3]._manType = ChessMan_T::PAWN_MAN;



        //Black SIDE
        _board[0][9]._color = ChessColor_T::BLACK_SIDE;
        _board[0][9]._manType = ChessMan_T::ROOK_MAN;

        _board[1][9]._color = ChessColor_T::BLACK_SIDE;
        _board[1][9]._manType = ChessMan_T::KNIGHT_MAN;

        _board[2][9]._color = ChessColor_T::BLACK_SIDE;
        _board[2][9]._manType = ChessMan_T::BISHOP_MAN;

        _board[3][9]._color = ChessColor_T::BLACK_SIDE;
        _board[3][9]._manType = ChessMan_T::QUEEN_MAN;

        _board[4][9]._color = ChessColor_T::BLACK_SIDE;
        _board[4][9]._manType = ChessMan_T::KING_MAN;

        _board[5][9]._color = ChessColor_T::BLACK_SIDE;
        _board[5][9]._manType = ChessMan_T::QUEEN_MAN;

        _board[6][9]._color = ChessColor_T::BLACK_SIDE;
        _board[6][9]._manType = ChessMan_T::BISHOP_MAN;

        _board[7][9]._color = ChessColor_T::BLACK_SIDE;
        _board[7][9]._manType = ChessMan_T::KNIGHT_MAN;

        _board[8][9]._color = ChessColor_T::BLACK_SIDE;
        _board[8][9]._manType = ChessMan_T::ROOK_MAN;


        _board[1][7]._color = ChessColor_T::BLACK_SIDE;
        _board[1][7]._manType = ChessMan_T::CANNON_MAN;

        _board[7][7]._color = ChessColor_T::BLACK_SIDE;
        _board[7][7]._manType = ChessMan_T::CANNON_MAN;

        _board[0][6]._color = ChessColor_T::BLACK_SIDE;
        _board[0][6]._manType = ChessMan_T::PAWN_MAN;

        _board[2][6]._color = ChessColor_T::BLACK_SIDE;
        _board[2][6]._manType = ChessMan_T::PAWN_MAN;

        _board[4][6]._color = ChessColor_T::BLACK_SIDE;
        _board[4][6]._manType = ChessMan_T::PAWN_MAN;

        _board[6][6]._color = ChessColor_T::BLACK_SIDE;
        _board[6][6]._manType = ChessMan_T::PAWN_MAN;

        _board[8][6]._color = ChessColor_T::BLACK_SIDE;
        _board[8][6]._manType = ChessMan_T::PAWN_MAN;
    }

    bool ChessBoard::SetBoardData(const ChineseBoardData_T& boardData)
    {
        m_board = boardData;
        return true;
    }
    int ChessBoard::GetRedKingIndex()
    {
        return 0;
    }
    int ChessBoard::GetBlackKingIndex()
    {
        return 9;
    }
    ChessBoard::ChessBoard()
    {
        _X_MAX_GRID = 9;
        _Y_MAX_GRID = 10;
        SetBoardToStartState();
    }
    bool ChessBoard::SwapSide()
    {
		int maxX = GetMaxX();
		int maxY = GetMaxY();
        ChineseBoardData_T targetBoard;
		ChineseBoardData_T sourceBoard = m_board;
        for (int x = 0; x < maxX; x++)
        {
            for (int y = 0; y < maxY; y++)
            {
                targetBoard._board[x][y]._color = sourceBoard._board[maxX - 1 - x][maxY - 1 - y]._color;
				targetBoard._board[x][y]._manType = sourceBoard._board[maxX - 1 - x][maxY - 1 - y]._manType;
            }
        }
		m_board = targetBoard;
        int temp = m_BlackKingIndex;
		m_BlackKingIndex = m_RedKingIndex;
        m_RedKingIndex = temp;
        return true;

    }
    std::vector<ChessGrid_T> ChessBoard::GetChessGrids(const ChessBoardElem_T& side) const
    {
        std::vector<ChessGrid_T> result;
		int maxX = GetMaxX();
		int maxY = GetMaxY();
        for(int x = 0 ; x < maxX; x++)
        {
            for (int y = 0; y < maxY;y++)
            {
                if (m_board._board[x][y]._color == side._color && m_board._board[x][y]._manType == side._manType)
                {
                    ChessGrid_T grid;
                    grid._gridX = x;
                    grid._gridY = y;
					result.push_back(grid);
                }
            }
		}
        return result;
    }
    std::vector<ChessGrid_T> ChessBoard::GetMoveableGrids(const ChessGrid_T& curGrid) const
    {
        std::vector<ChessGrid_T> result;
        if (IsGridInBoard(curGrid))
        {
            for (int xIndex = 0; xIndex < GetMaxX(); xIndex++)
            {
                for (int yIndex = 0; yIndex < GetMaxY(); yIndex++)
                {
                    ChessGrid_T targetGrid;
                    targetGrid._gridX = xIndex;
                    targetGrid._gridY = yIndex;
                    ChessMove_T moveAct;
                    moveAct._fromGrid = curGrid;
                    moveAct._toGrid = targetGrid;
                    moveAct._chessMan = GetGridChess(curGrid);
                    if (CanMove(moveAct))
                    {
                        result.push_back(targetGrid);
                    }
                }
            }
        }
		return result;
    }
    const ChessBoardElem_T& ChessBoard::GetGridChess(const ChessGrid_T& grid) const
    {
        if (IsGoodSelectedGrid(grid))
        {
            auto result = m_board._board[grid._gridX][grid._gridY];
            return result;
        }
        ChessBoardElem_T result;
        return result;
    }
    const ChineseBoardData_T& ChessBoard::GetBoardData()
    {
        return m_board;
    }

    bool ChessBoard::IsGridInBoard(const ChessGrid_T& grid) const
    {
        if (0 <= grid._gridX && grid._gridX < _X_MAX_GRID)
        {
            if (0 <= grid._gridY && grid._gridY < _Y_MAX_GRID)
            {
                return true;
            }
        }
        return false;
    }
    bool ChessBoard::IsChessInGrid(const ChessGrid_T& grid, const ChessBoardElem_T& chess) const
    {
        if (IsGridInBoard(grid))
        {
            ChessBoardElem_T elem = m_board._board[grid._gridX][grid._gridY];
            if (chess._color == elem._color && chess._manType == elem._manType)
            {
                return true;
            }
        }
        return false;
    }

    bool ChessBoard::IsGoodSelectedGrid(const ChessGrid_T& grid) const
    {
        if (IsGridInBoard(grid))
        {
            return true;
        }
        return false;
    }
    bool ChessBoard::IsGoodTargetGrid(const ChessGrid_T& origGrid, const ChessGrid_T& targetGrid) const
    {
        if (IsGridInBoard(origGrid) && IsGridInBoard(targetGrid))
        {
            return true;
        }
        return false;
    }
    bool ChessBoard::CanRookMove(const ChessMove_T& moveAct) const
    {
        auto& _board = m_board._board;
        //Rook
        if (moveAct._chessMan._manType == ChessMan_T::ROOK_MAN)
        {
            if (moveAct._fromGrid._gridX == moveAct._toGrid._gridX)
            {
                int chessX = moveAct._fromGrid._gridX;
                if (moveAct._fromGrid._gridY < moveAct._toGrid._gridY)
                {
                    for (int yIndex = moveAct._fromGrid._gridY + 1; yIndex < moveAct._toGrid._gridY;yIndex++)
                    {
                        if (_board[chessX][yIndex]._manType != ChessMan_T::NONE_MAN)
                        {
                            return false;
                        }
                    }
                }
                if (moveAct._fromGrid._gridY > moveAct._toGrid._gridY)
                {
                    for (int yIndex = moveAct._fromGrid._gridY - 1; yIndex > moveAct._toGrid._gridY;yIndex--)
                    {
                        if (_board[chessX][yIndex]._manType != ChessMan_T::NONE_MAN)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            if (moveAct._fromGrid._gridY == moveAct._toGrid._gridY)
            {
                int chessY = moveAct._fromGrid._gridY;
                if (moveAct._fromGrid._gridX < moveAct._toGrid._gridX)
                {
                    for (int xIndex = moveAct._fromGrid._gridX + 1; xIndex < moveAct._toGrid._gridX;xIndex++)
                    {
                        if (_board[xIndex][chessY]._manType != ChessMan_T::NONE_MAN)
                        {
                            return false;
                        }
                    }
                }
                if (moveAct._fromGrid._gridX > moveAct._toGrid._gridX)
                {
                    for (int xIndex = moveAct._fromGrid._gridX - 1; xIndex > moveAct._toGrid._gridX;xIndex--)
                    {
                        if (_board[xIndex][chessY]._manType != ChessMan_T::NONE_MAN)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }
    bool ChessBoard::CanKnightMove(const ChessMove_T& moveAct) const
    {
        auto& _board = m_board._board;
        if (moveAct._chessMan._manType == ChessMan_T::KNIGHT_MAN)
        {
            ChessGrid_T origGrid = moveAct._fromGrid;
            ChessGrid_T targetGrid = moveAct._toGrid;
            bool bCanMove = false;
            //Left Up
            if (origGrid._gridX - 2 == targetGrid._gridX && origGrid._gridY - 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX - 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }
            //Left Down
            if (origGrid._gridX - 2 == targetGrid._gridX && origGrid._gridY + 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX - 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }

            //Right Up
            if (origGrid._gridX + 2 == targetGrid._gridX && origGrid._gridY - 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX + 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }
            //Right Down
            if (origGrid._gridX + 2 == targetGrid._gridX && origGrid._gridY + 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX + 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }

            //Up Left
            if (origGrid._gridX - 1 == targetGrid._gridX && origGrid._gridY - 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY - 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }
            //Up Right
            if (origGrid._gridX + 1 == targetGrid._gridX && origGrid._gridY - 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY - 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }

            //Down Left
            if (origGrid._gridX - 1 == targetGrid._gridX && origGrid._gridY + 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY + 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }
            //Down Right
            if (origGrid._gridX + 1 == targetGrid._gridX && origGrid._gridY + 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY + 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }
            if (bCanMove)
            {
                return true;
            }
            
        }
        return false;
    }
    bool ChessBoard::CanBishopMove(const ChessMove_T& moveAct) const
    {
        auto& _board = m_board._board;
        if (moveAct._chessMan._manType == ChessMan_T::BISHOP_MAN)
        {
            ChessGrid_T origGrid = moveAct._fromGrid;
            ChessGrid_T targetGrid = moveAct._toGrid;
            int FORBIDDEN_Y_INDEX1 = 3;
            int FORBIDDEN_Y_INDEX2 = 6;
            if (targetGrid._gridY == FORBIDDEN_Y_INDEX1 || targetGrid._gridY == FORBIDDEN_Y_INDEX2)
            {
                return false;
            }
            bool bCanMove = false;
            //Left Up
            if (origGrid._gridX - 2 == targetGrid._gridX && origGrid._gridY - 2 == targetGrid._gridY)
            {
                //Bishop was blocked by the square center chess
                if (_board[origGrid._gridX - 1][origGrid._gridY - 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }

            //Left Down
            if (origGrid._gridX - 2 == targetGrid._gridX && origGrid._gridY + 2 == targetGrid._gridY)
            {
                //Bishop was blocked by the square center chess
                if (_board[origGrid._gridX - 1][origGrid._gridY + 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }

            //Right Up
            if (origGrid._gridX + 2 == targetGrid._gridX && origGrid._gridY - 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX + 1][origGrid._gridY - 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }

            //Right Down
            if (origGrid._gridX + 2 == targetGrid._gridX && origGrid._gridY + 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX + 1][origGrid._gridY + 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
                bCanMove = true;
            }
            if (bCanMove)
            {
                return true;
            }
        }
        return false;
    }
    bool ChessBoard::CanQueenMove(const ChessMove_T& moveAct) const
    {
        auto& _board = m_board._board;
        if (moveAct._chessMan._manType == ChessMan_T::QUEEN_MAN)
        {
            ChessGrid_T origGrid = moveAct._fromGrid;
            ChessGrid_T targetGrid = moveAct._toGrid;
            int QUEEN_MOVE_MIN_X = 3;
            int QUEEN_MOVE_MAX_X = 5;

            int QUEEN_MOVE_MIN_Y = 2;
            int QUEEN_MOVE_MAX_Y = 7;

            if (abs(origGrid._gridX - targetGrid._gridX) == 1 && abs(origGrid._gridY - targetGrid._gridY) == 1)
            {
                if (QUEEN_MOVE_MIN_X <= targetGrid._gridX && targetGrid._gridX <= QUEEN_MOVE_MAX_X)
                {
                    if (targetGrid._gridY <= QUEEN_MOVE_MIN_Y || targetGrid._gridY >= QUEEN_MOVE_MAX_Y)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool ChessBoard::CanKingMove(const ChessMove_T& moveAct) const
    {
        auto& _board = m_board._board;
        //King
        if (moveAct._chessMan._manType == ChessMan_T::KING_MAN)
        {
            ChessGrid_T origGrid = moveAct._fromGrid;
            ChessGrid_T targetGrid = moveAct._toGrid;
            int KING_MOVE_MIN_X = 3;
            int KING_MOVE_MAX_X = 5;

            int KING_MOVE_MIN_Y = 2;
            int KING_MOVE_MAX_Y = 7;
            if (abs(origGrid._gridX - targetGrid._gridX) + abs(origGrid._gridY - targetGrid._gridY) == 1)
            {
                if (KING_MOVE_MIN_X <= targetGrid._gridX && targetGrid._gridX <= KING_MOVE_MAX_X)
                {
                    if (targetGrid._gridY <= KING_MOVE_MIN_Y || targetGrid._gridY >= KING_MOVE_MAX_Y)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool ChessBoard::CanCannonMove(const ChessMove_T& moveAct) const
    {
        auto& _board = m_board._board;
        ChessBoardElem_T toElem = _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY];
        //Cannon
        if (moveAct._chessMan._manType == ChessMan_T::CANNON_MAN)
        {
            int middelChessCount = 0;
            if (moveAct._fromGrid._gridX == moveAct._toGrid._gridX)
            {
                middelChessCount = 0;
                int chessX = moveAct._fromGrid._gridX;
                if (moveAct._fromGrid._gridY < moveAct._toGrid._gridY)
                {
                    for (int yIndex = moveAct._fromGrid._gridY + 1; yIndex < moveAct._toGrid._gridY;yIndex++)
                    {
                        if (_board[chessX][yIndex]._manType != ChessMan_T::NONE_MAN)
                        {
                            middelChessCount += 1;
                        }
                    }
                }
                if (moveAct._fromGrid._gridY > moveAct._toGrid._gridY)
                {
                    for (int yIndex = moveAct._fromGrid._gridY - 1; yIndex > moveAct._toGrid._gridY;yIndex--)
                    {
                        if (_board[chessX][yIndex]._manType != ChessMan_T::NONE_MAN)
                        {
                            middelChessCount += 1;
                        }
                    }
                }

                //move like Rook
                if ((middelChessCount == 0 && toElem._manType == ChessMan_T::NONE_MAN))
                {
                    return true;
                }

                //eat other chess
                if (middelChessCount == 1)
                {
                    auto& fromElem = _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY];

                    if (fromElem._color == ChessColor_T::RED_SIDE && toElem._color == ChessColor_T::BLACK_SIDE)
                    {
                        return true;
                    }

                    if (fromElem._color == ChessColor_T::BLACK_SIDE && toElem._color == ChessColor_T::RED_SIDE)
                    {
                        return true;
                    }
                }
            }
            if (moveAct._fromGrid._gridY == moveAct._toGrid._gridY)
            {
                middelChessCount = 0;
                int chessY = moveAct._fromGrid._gridY;
                if (moveAct._fromGrid._gridX < moveAct._toGrid._gridX)
                {
                    for (int xIndex = moveAct._fromGrid._gridX + 1; xIndex < moveAct._toGrid._gridX;xIndex++)
                    {
                        if (_board[xIndex][chessY]._manType != ChessMan_T::NONE_MAN)
                        {
                            middelChessCount += 1;
                        }
                    }
                }
                if (moveAct._fromGrid._gridX > moveAct._toGrid._gridX)
                {
                    for (int xIndex = moveAct._fromGrid._gridX - 1; xIndex > moveAct._toGrid._gridX;xIndex--)
                    {
                        if (_board[xIndex][chessY]._manType != ChessMan_T::NONE_MAN)
                        {
                            middelChessCount += 1;
                        }
                    }
                }
                //move like Rook
                if ((middelChessCount == 0 && toElem._manType == ChessMan_T::NONE_MAN))
                {
                    return true;
                }

				//eat other chess
                if(middelChessCount == 1)
                {
					auto& fromElem = _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY];
                    
                    if(fromElem._color == ChessColor_T::RED_SIDE && toElem._color == ChessColor_T::BLACK_SIDE)
                    {
                        return true;
					}

                    if (fromElem._color == ChessColor_T::BLACK_SIDE && toElem._color == ChessColor_T::RED_SIDE)
                    {
                        return true;
                    }
				}
            }
        }
		return false;
    }

    bool ChessBoard::CanMove(const ChessMove_T& moveAct) const
    {
        auto& _board = m_board._board;
        if (IsChessInGrid(moveAct._fromGrid, moveAct._chessMan) &&
            IsGridInBoard(moveAct._toGrid))
        {
            //bool bCanMove = false;
            //Can not eat yourself
            ChessBoardElem_T toElem = _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY];
            if (toElem._color == moveAct._chessMan._color)
            {
                return false;
            }
            bool bCanMove = false;
            //Rook
            if (moveAct._chessMan._manType == ChessMan_T::ROOK_MAN)
            {
                bCanMove = CanRookMove(moveAct);
            }

            //Knight
            if (moveAct._chessMan._manType == ChessMan_T::KNIGHT_MAN)
            {
                bCanMove = CanKnightMove(moveAct);
            }
            //Bishop
            if (moveAct._chessMan._manType == ChessMan_T::BISHOP_MAN)
            {
                bCanMove = CanBishopMove(moveAct);
            }

            //Queen
            if (moveAct._chessMan._manType == ChessMan_T::QUEEN_MAN)
            {
                bCanMove = CanQueenMove(moveAct);
            }
            //King
            if (moveAct._chessMan._manType == ChessMan_T::KING_MAN)
            {
                bCanMove = CanKingMove(moveAct);
            }

            //Cannon
            if (moveAct._chessMan._manType == ChessMan_T::CANNON_MAN)
            {
                bCanMove = CanCannonMove(moveAct);
            }
            if (moveAct._chessMan._manType == ChessMan_T::PAWN_MAN)
            {
                bCanMove = CanPawnMove(moveAct);
            }
            return bCanMove;
        }
        return false;
	}

    bool ChessBoard::OnMove(const ChessMove_T& moveAct)
    {
        
        if(CanMove(moveAct))
        {
            auto& _board = m_board._board;
            _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor_T::NONE_SIDE;
            _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

            _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
            _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
            return true;
            
        }
        return false;
    }

    bool ChessBoard::CanPawnMove(const ChessMove_T& moveAct) const
    {

        if (moveAct._chessMan._manType == ChessMan_T::PAWN_MAN)
        {
            bool bCrossRiver = false;
            bool bCanMove = false;

            //Pawn can only move one step at a time
            if (abs(moveAct._toGrid._gridX - moveAct._fromGrid._gridX) + abs(moveAct._toGrid._gridY - moveAct._fromGrid._gridY) != 1)
            {
                return false;
            }
            auto& _board = m_board._board;
            int UP_RIVER_SIDE = 4;
            int DOWN_RIVER_SIDE = 5;

            if (moveAct._chessMan._color == ChessColor_T::RED_SIDE)
            {
                if (0 == m_RedKingIndex)
                {
                    //Down,cross river
                    if (moveAct._fromGrid._gridY >= DOWN_RIVER_SIDE)
                    {
                        if (moveAct._toGrid._gridY >= moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                    else
                    {
                        if (moveAct._toGrid._gridY > moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                }
                if (9 == m_RedKingIndex)
                {
                    //Down,cross river
                    if (moveAct._fromGrid._gridY <= UP_RIVER_SIDE)
                    {
                        if (moveAct._toGrid._gridY <= moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                    else
                    {
                        if (moveAct._toGrid._gridY < moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                }
            }
            if (moveAct._chessMan._color == ChessColor_T::BLACK_SIDE)
            {
                if (0 == m_BlackKingIndex)
                {
                    //Down,cross river
                    if (moveAct._fromGrid._gridY >= DOWN_RIVER_SIDE)
                    {
                        if (moveAct._toGrid._gridY >= moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                    else
                    {
                        if (moveAct._toGrid._gridY > moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                }
                if (9 == m_BlackKingIndex)
                {
                    //Down,cross river
                    if (moveAct._fromGrid._gridY <= UP_RIVER_SIDE)
                    {
                        if (moveAct._toGrid._gridY <= moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                    else
                    {
                        if (moveAct._toGrid._gridY < moveAct._fromGrid._gridY)
                        {
                            bCanMove = true;
                        }
                    }
                }

            }
            if (bCanMove)
            {
                return true;
            }
        }
        return false;
    }
    
    std::vector<ChessMove_T> ChessBoard::GetAllCheckMoves(ChessColor_T side) const
    {
        std::vector<ChessMove_T> result;
        std::vector<ChessGrid_T> otherSideChessGrids;
        {
            ChessGrid_T kingGrid;
            auto& _board = m_board._board;
            int maxX = GetMaxX();
            int maxY = GetMaxY();
            for (int xIndex = 0; xIndex < maxX; xIndex++)
            {
                for (int yIndex = 0; yIndex < maxY; yIndex++)
                {
                    ChessGrid_T grid;
                    grid._gridX = xIndex;
                    grid._gridY = yIndex;
                    ChessBoardElem_T elem = _board[xIndex][yIndex];
                    if (elem._color != side && elem._color != ChessColor_T::NONE_SIDE)
                    {
                        otherSideChessGrids.push_back(grid);
                    }
                }
            }
        }
        bool bCheck = false;
        for (const ChessGrid_T& otherSideChessGrid : otherSideChessGrids)
        {
            auto moveableGrids = GetMoveableGrids(otherSideChessGrid);
            for (const ChessGrid_T& moveableGrid : moveableGrids)
            {
                auto& toGrid = GetGridChess(moveableGrid);
                if (toGrid._color == side && toGrid._manType == ChessMan_T::KING_MAN)
                {
                    ChessMove_T moveAct;
                    moveAct._fromGrid = otherSideChessGrid;
                    moveAct._toGrid = moveableGrid;
                    moveAct._chessMan = GetGridChess(otherSideChessGrid);
                    result.push_back(moveAct);
                }
            }
        }
        return result;
    }

    bool ChessBoard::IsSideInCheck(ChessColor_T side) const
    {
        std::vector<ChessMove_T> result = GetAllCheckMoves(side);
		bool bInCheck = !result.empty();
        return bInCheck;
    }