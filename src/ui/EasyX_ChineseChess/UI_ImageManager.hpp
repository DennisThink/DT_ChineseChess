#ifndef _DT_CHINESE_CHESS_IMAGE_MANAGER_H_
#define _DT_CHINESE_CHESS_IMAGE_MANAGER_H_
#include "chess_types.hpp"
#include <vector>
#include <easyx.h>
struct ChessManElem
{
	int _posX;
	int _posY;
	IMAGE _img;
};

struct ImageElem
{
	ChessColor _color;
	ChessMan_T _manType;
	IMAGE _img;
};
class ChessManImageManager
{
public:
	IMAGE GetChessManImage(ChessColor color, ChessMan_T manType);
	IMAGE GetBoardImage();
	IMAGE GetChessManMaskImage();
	ChessManImageManager();
private:
	std::vector<ImageElem> _imgArray;
	IMAGE _boardImage;
	IMAGE _chessManMaskImage;
};
#endif