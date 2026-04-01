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
                _board[x][y]._color = ChessColor::NONE_SIDE;
                _board[x][y]._manType = ChessMan_T::NONE_MAN;
            }
        }
        m_RedKingIndex = 0;
        m_BlackKingIndex = 9;
        //RED SIDE
        _board[0][0]._color = ChessColor::RED_SIDE;
        _board[0][0]._manType = ChessMan_T::ROOK_MAN;

        _board[1][0]._color = ChessColor::RED_SIDE;
        _board[1][0]._manType = ChessMan_T::KNIGHT_MAN;

        _board[2][0]._color = ChessColor::RED_SIDE;
        _board[2][0]._manType = ChessMan_T::BISHOP_MAN;

        _board[3][0]._color = ChessColor::RED_SIDE;
        _board[3][0]._manType = ChessMan_T::QUEEN_MAN;

        _board[4][0]._color = ChessColor::RED_SIDE;
        _board[4][0]._manType = ChessMan_T::KING_MAN;

        _board[5][0]._color = ChessColor::RED_SIDE;
        _board[5][0]._manType = ChessMan_T::QUEEN_MAN;

        _board[6][0]._color = ChessColor::RED_SIDE;
        _board[6][0]._manType = ChessMan_T::BISHOP_MAN;

        _board[7][0]._color = ChessColor::RED_SIDE;
        _board[7][0]._manType = ChessMan_T::KNIGHT_MAN;

        _board[8][0]._color = ChessColor::RED_SIDE;
        _board[8][0]._manType = ChessMan_T::ROOK_MAN;


        _board[1][2]._color = ChessColor::RED_SIDE;
        _board[1][2]._manType = ChessMan_T::CANNON_MAN;

        _board[7][2]._color = ChessColor::RED_SIDE;
        _board[7][2]._manType = ChessMan_T::CANNON_MAN;

        _board[0][3]._color = ChessColor::RED_SIDE;
        _board[0][3]._manType = ChessMan_T::PAWN_MAN;

        _board[2][3]._color = ChessColor::RED_SIDE;
        _board[2][3]._manType = ChessMan_T::PAWN_MAN;

        _board[4][3]._color = ChessColor::RED_SIDE;
        _board[4][3]._manType = ChessMan_T::PAWN_MAN;

        _board[6][3]._color = ChessColor::RED_SIDE;
        _board[6][3]._manType = ChessMan_T::PAWN_MAN;

        _board[8][3]._color = ChessColor::RED_SIDE;
        _board[8][3]._manType = ChessMan_T::PAWN_MAN;



        //Black SIDE
        _board[0][9]._color = ChessColor::BLACK_SIDE;
        _board[0][9]._manType = ChessMan_T::ROOK_MAN;

        _board[1][9]._color = ChessColor::BLACK_SIDE;
        _board[1][9]._manType = ChessMan_T::KNIGHT_MAN;

        _board[2][9]._color = ChessColor::BLACK_SIDE;
        _board[2][9]._manType = ChessMan_T::BISHOP_MAN;

        _board[3][9]._color = ChessColor::BLACK_SIDE;
        _board[3][9]._manType = ChessMan_T::QUEEN_MAN;

        _board[4][9]._color = ChessColor::BLACK_SIDE;
        _board[4][9]._manType = ChessMan_T::KING_MAN;

        _board[5][9]._color = ChessColor::BLACK_SIDE;
        _board[5][9]._manType = ChessMan_T::QUEEN_MAN;

        _board[6][9]._color = ChessColor::BLACK_SIDE;
        _board[6][9]._manType = ChessMan_T::BISHOP_MAN;

        _board[7][9]._color = ChessColor::BLACK_SIDE;
        _board[7][9]._manType = ChessMan_T::KNIGHT_MAN;

        _board[8][9]._color = ChessColor::BLACK_SIDE;
        _board[8][9]._manType = ChessMan_T::ROOK_MAN;


        _board[1][7]._color = ChessColor::BLACK_SIDE;
        _board[1][7]._manType = ChessMan_T::CANNON_MAN;

        _board[7][7]._color = ChessColor::BLACK_SIDE;
        _board[7][7]._manType = ChessMan_T::CANNON_MAN;

        _board[0][6]._color = ChessColor::BLACK_SIDE;
        _board[0][6]._manType = ChessMan_T::PAWN_MAN;

        _board[2][6]._color = ChessColor::BLACK_SIDE;
        _board[2][6]._manType = ChessMan_T::PAWN_MAN;

        _board[4][6]._color = ChessColor::BLACK_SIDE;
        _board[4][6]._manType = ChessMan_T::PAWN_MAN;

        _board[6][6]._color = ChessColor::BLACK_SIDE;
        _board[6][6]._manType = ChessMan_T::PAWN_MAN;

        _board[8][6]._color = ChessColor::BLACK_SIDE;
        _board[8][6]._manType = ChessMan_T::PAWN_MAN;
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
    const ChessManBoardElem& ChessBoard::GetGridChess(const ChessGrid_T& grid)
    {
        if (IsGoodSelectedGrid(grid))
        {
            return m_board._board[grid._gridX][grid._gridY];
        }
        ChessManBoardElem result;
        return result;
    }
    const ChineseBoardData_T& ChessBoard::GetBoardData()
    {
        return m_board;
    }

    bool ChessBoard::IsGridInBoard(const ChessGrid_T& grid)
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
    bool ChessBoard::IsChessInGrid(const ChessGrid_T& grid, const ChessManBoardElem& chess)
    {
        if (IsGridInBoard(grid))
        {
            ChessManBoardElem elem = m_board._board[grid._gridX][grid._gridY];
            if (chess._color == elem._color && chess._manType == elem._manType)
            {
                return true;
            }
        }
        return false;
    }

    bool ChessBoard::IsGoodSelectedGrid(const ChessGrid_T& grid)
    {
        if (IsGridInBoard(grid))
        {
            return true;
        }
        return false;
    }
    bool ChessBoard::IsGoodTargetGrid(const ChessGrid_T& origGrid, const ChessGrid_T& targetGrid)
    {
        if (IsGridInBoard(origGrid) && IsGridInBoard(targetGrid))
        {
            return true;
        }
        return false;
    }
    bool ChessBoard::OnRookMove(const ChessMove_T& moveAct)
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
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor::NONE_SIDE;
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
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
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor::NONE_SIDE;
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
            }
        }
        return true;
    }
    bool ChessBoard::OnKnightMove(const ChessMove_T& moveAct)
    {
        auto& _board = m_board._board;
        if (moveAct._chessMan._manType == ChessMan_T::KNIGHT_MAN)
        {
            ChessGrid_T origGrid = moveAct._fromGrid;
            ChessGrid_T targetGrid = moveAct._toGrid;
            //Left Up
            if (origGrid._gridX - 2 == targetGrid._gridX && origGrid._gridY - 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX - 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }
            //Left Down
            if (origGrid._gridX - 2 == targetGrid._gridX && origGrid._gridY + 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX - 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }

            //Right Up
            if (origGrid._gridX + 2 == targetGrid._gridX && origGrid._gridY - 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX + 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }
            //Right Down
            if (origGrid._gridX + 2 == targetGrid._gridX && origGrid._gridY + 1 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX + 1][origGrid._gridY]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }

            //Up Left
            if (origGrid._gridX - 1 == targetGrid._gridX && origGrid._gridY - 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY - 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }
            //Up Right
            if (origGrid._gridX + 1 == targetGrid._gridX && origGrid._gridY - 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY - 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }

            //Down Left
            if (origGrid._gridX - 1 == targetGrid._gridX && origGrid._gridY + 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY + 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }
            //Down Right
            if (origGrid._gridX + 1 == targetGrid._gridX && origGrid._gridY + 2 == targetGrid._gridY)
            {
                if (_board[origGrid._gridX][origGrid._gridY + 1]._manType != ChessMan_T::NONE_MAN)
                {
                    return false;
                }
            }
            _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor::NONE_SIDE;
            _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

            _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
            _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
        }
        return true;
    }
    bool ChessBoard::OnBishopMove(const ChessMove_T& moveAct)
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
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor::NONE_SIDE;
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
            }

            return true;
        }
    }
    bool ChessBoard::OnQueenMove(const ChessMove_T& moveAct)
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
                        _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor::NONE_SIDE;
                        _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

                        _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
                        _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool ChessBoard::OnKingMove(const ChessMove_T& moveAct)
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
                        _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor::NONE_SIDE;
                        _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

                        _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
                        _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool ChessBoard::OnCannonMove(const ChessMove_T& moveAct)
    {
        auto& _board = m_board._board;
        ChessManBoardElem toElem = _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY];
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
            }
            if ((middelChessCount == 0 && toElem._manType == ChessMan_T::NONE_MAN) || (middelChessCount == 1))
            {
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._color = ChessColor::NONE_SIDE;
                _board[moveAct._fromGrid._gridX][moveAct._fromGrid._gridY]._manType = ChessMan_T::NONE_MAN;

                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._color = moveAct._chessMan._color;
                _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY]._manType = moveAct._chessMan._manType;
                return true;
            }
        }
		return false;
    }
    bool ChessBoard::OnMove(const ChessMove_T& moveAct)
    {
        auto& _board = m_board._board;
        if (IsChessInGrid(moveAct._fromGrid, moveAct._chessMan) &&
            IsGridInBoard(moveAct._toGrid))
        {
            //Can not eat yourself
            ChessManBoardElem toElem = _board[moveAct._toGrid._gridX][moveAct._toGrid._gridY];
            if (toElem._color == moveAct._chessMan._color)
            {
                return false;
            }
            //Rook
            if (moveAct._chessMan._manType == ChessMan_T::ROOK_MAN)
            {
                return OnRookMove(moveAct);
            }

            //Knight
            if (moveAct._chessMan._manType == ChessMan_T::KNIGHT_MAN)
            {
                return OnKnightMove(moveAct);
            }
            //Bishop
            if (moveAct._chessMan._manType == ChessMan_T::BISHOP_MAN)
            {
                return OnBishopMove(moveAct);
            }

            //Queen
            if (moveAct._chessMan._manType == ChessMan_T::QUEEN_MAN)
            {
                return OnQueenMove(moveAct);
            }
            //King
            if (moveAct._chessMan._manType == ChessMan_T::KING_MAN)
            {
                return OnKingMove(moveAct);
            }

            //Cannon
            if (moveAct._chessMan._manType == ChessMan_T::CANNON_MAN)
            {
                return OnCannonMove(moveAct);
            }
        }
       
        return false;
    }