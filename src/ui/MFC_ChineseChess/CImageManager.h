#ifndef _C_IMAGE_MANAGER_H_
#define _C_IMAGE_MANAGER_H_
#include <Atlimage.h>
#include "chess_types.hpp"
class CImageManager
{
public:
	const CImage& GetChessManImage(ChessColor color, ChessMan_T manType);
	const CImage& GetBoardImage();
	const CImage& GetChessManMaskImage();
	CImageManager();
private:
	CImage m_boardImage;
	CImage m_ChessManMaskImage;
	CImage m_ChessManImages[ChessColor::SIDE_COUNT][ChessMan_T::MAN_COUNT];
};
#endif