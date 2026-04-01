#include "QPixmapManager.h"
#include <qbitmap.h>
#include "chess_types.hpp"
#include <iostream>
QPixmapManager::QPixmapManager()
{
	if (m_boardImage.load("main.gif"))
	{

	}
	else
	{
		std::cout<< "load board failed";
	}

	if (m_ChessManMaskImage.load("mask.bmp"))
	{

	}
	else
	{
		std::cout << "load mask failed";
	}

	QString allImageNames[ChessColor::SIDE_COUNT][ChessMan_T::MAN_COUNT] = {
		{("red_rook.bmp"),
		("red_knight.bmp"),
		("red_bishop.bmp"),
		("red_queen.bmp"),
		("red_king.bmp"),
		("red_cannon.bmp"),
		("red_pawn.bmp")},
		{("black_rook.bmp"),
		("black_knight.bmp"),
		("black_bishop.bmp"),
		("black_queen.bmp"),
		("black_king.bmp"),
		("black_cannon.bmp"),
		("black_pawn.bmp")}
	};
	QBitmap maskBitmap = m_ChessManMaskImage.createMaskFromColor(Qt::white);
	for (int sideIndex = 0; sideIndex < ChessColor::SIDE_COUNT; sideIndex++)
	{
		for (int manIndex = 0; manIndex < ChessMan_T::MAN_COUNT; manIndex++)
		{
			if (m_ChessManImages[sideIndex][manIndex].load(allImageNames[sideIndex][manIndex]))
			{
				m_ChessManImages[sideIndex][manIndex].setMask(maskBitmap);
			}
			else
			{
				std::cout << "Load Image:[" << allImageNames[sideIndex][manIndex].toStdString() << "]  Failed";
			}
		}
	}
}

const QPixmap& QPixmapManager::GetChessManImage(ChessColor color, ChessMan_T manType)
{
	int colorStart = static_cast<int>(ChessColor::NONE_SIDE);
	int colorEnd = static_cast<int>(ChessColor::SIDE_COUNT);
	int colorIndex = static_cast<int>(color);


	int typeStart = static_cast<int>(ChessMan_T::NONE_MAN);
	int typeEnd = static_cast<int>(ChessMan_T::MAN_COUNT);
	int typeIndex = static_cast<int>(manType);
	if ((colorStart < colorIndex && colorIndex < colorEnd) &&
		(typeStart < typeIndex && typeIndex < typeEnd))
	{
		return m_ChessManImages[colorIndex][typeIndex];
	}
	QPixmap image;
	return image;
}
const QPixmap& QPixmapManager::GetBoardImage()
{
	return m_boardImage;
}
const QPixmap& QPixmapManager::GetChessManMaskImage()
{
	return m_ChessManMaskImage;
}