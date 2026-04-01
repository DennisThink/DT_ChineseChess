#ifndef _Q_PIXMAP_MANAGER_H_
#define _Q_PIXMAP_MANAGER_H_
#include <qpixmap.h>
#include "chess_types.hpp"
class QPixmapManager
{
public:
	const QPixmap& GetChessManImage(ChessColor color, ChessMan_T manType);
	const QPixmap& GetBoardImage();
	const QPixmap& GetChessManMaskImage();
	QPixmapManager();
private:
	QPixmap m_boardImage;
	QPixmap m_ChessManMaskImage;
	QPixmap m_ChessManImages[ChessColor::SIDE_COUNT][ChessMan_T::MAN_COUNT];
};
#endif