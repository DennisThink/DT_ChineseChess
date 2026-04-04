#ifndef _DT_CHINESE_CHESS_CHESS_TYPES_H_
#define _DT_CHINESE_CHESS_CHESS_TYPES_H_
#include <string>
enum ChessColor_T
{
    NONE_SIDE = -1,
    RED_SIDE = 0,
    BLACK_SIDE = 1,
    SIDE_COUNT = 2,
};

enum ChessMan_T
{
    NONE_MAN = -1,
    ROOK_MAN = 0,
    KNIGHT_MAN = 1,
    BISHOP_MAN = 2,
    QUEEN_MAN = 3,
    KING_MAN = 4,
    CANNON_MAN = 5,
    PAWN_MAN = 6,
    MAN_COUNT = 7,
};

struct ChessBoardElem_T
{
    ChessBoardElem_T() { _color = ChessColor_T::NONE_SIDE;_manType = ChessMan_T::NONE_MAN; }
    ChessColor_T _color;
    ChessMan_T _manType;
};
struct ChessGrid_T
{
    ChessGrid_T()
    {
        Reset();
	}
    void Reset(){
        _gridX = -1;
        _gridY = -1;
    }
    int _gridX;
    int _gridY;
};

struct ChessMove_T
{
    ChessBoardElem_T _chessMan;
    ChessGrid_T _fromGrid;
    ChessGrid_T _toGrid;
};

struct ChessBoardGrid_T
{
    ChessBoardElem_T _elem;
    ChessGrid_T _grid;
};
struct ChineseBoardData_T
{
    ChessBoardElem_T _board[9][10];
};
std::string ToString(const ChessColor_T& color);
std::string ToString(const ChessMan_T& type);
std::string ToString(const ChessBoardElem_T& elem);
std::string ToString(const ChessGrid_T& grid);
std::string ToString(const ChessMove_T& move);
#endif