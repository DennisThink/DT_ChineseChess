#ifndef _C_IMAGE_MANAGER_H_
#define _C_IMAGE_MANAGER_H_
#include <Atlimage.h>
#include "chess_types.hpp"
class CImageManager
{
public:
	const CImage& GetChessManImage(ChessColor_T color, ChessMan_T manType);
	const CImage& GetBoardImage();
	const CImage& GetChessManMaskImage();
	CImageManager();
private:
	CImage m_boardImage;
	CImage m_ChessManMaskImage;
	CImage m_ChessManImages[ChessColor_T::SIDE_COUNT][ChessMan_T::MAN_COUNT];
};
#endif