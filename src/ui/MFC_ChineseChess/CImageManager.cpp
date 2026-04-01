#include "CImageManager.h"

const CImage& CImageManager::GetChessManImage(ChessColor color, ChessMan_T manType)
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
	CImage image;
	return image;
}

const CImage& CImageManager::GetBoardImage()
{
	return m_boardImage;
}

const CImage& CImageManager::GetChessManMaskImage()
{
	return m_ChessManMaskImage;
}

CImageManager::CImageManager()
{
	HRESULT hr = m_boardImage.Load(_T("main.gif"));  // 或 _T("image.png")

	if (SUCCEEDED(hr)) {
	}
	else {
		// 加载失败处理
	}
	HRESULT hr2 = m_ChessManMaskImage.Load(_T("mask.bmp"));  // 或 _T("image.png")

	if (SUCCEEDED(hr2)) {
	}
	else {
		// 加载失败处理
	}
	CString allImageNames[ChessColor::SIDE_COUNT][ChessMan_T::MAN_COUNT] = {
		{_T("red_rook.bmp"),
		_T("red_knight.bmp"),
		_T("red_bishop.bmp"),
		_T("red_queen.bmp"),
		_T("red_king.bmp"),
		_T("red_cannon.bmp"),
		_T("red_pawn.bmp")},
		{_T("black_rook.bmp"),
		_T("black_knight.bmp"),
		_T("black_bishop.bmp"),
		_T("black_queen.bmp"),
		_T("black_king.bmp"),
		_T("black_cannon.bmp"),
		_T("black_pawn.bmp")}
	};
	for (int sideIndex = 0; sideIndex < ChessColor::SIDE_COUNT; sideIndex++)
	{
		for (int manIndex = 0; manIndex < ChessMan_T::MAN_COUNT; manIndex++) 
		{
			m_ChessManImages[sideIndex][manIndex].Load(allImageNames[sideIndex][manIndex]);
		}
	}
}