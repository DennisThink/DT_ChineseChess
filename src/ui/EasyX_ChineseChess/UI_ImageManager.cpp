#include "UI_ImageManager.hpp"
#include "chess_types.hpp"
#include <iostream>
#include <easyx.h>
    IMAGE ChessManImageManager::GetChessManImage(ChessColor color, ChessMan_T manType)
    {
        for (auto item : _imgArray)
        {
            if (item._color == color && item._manType == manType)
            {
                return item._img;
            }
        }
        IMAGE img;
        return img;
    }

    IMAGE ChessManImageManager::GetBoardImage()
    {
        return _boardImage;
    }

    IMAGE ChessManImageManager::GetChessManMaskImage()
    {
        return _chessManMaskImage;
    }
    ChessManImageManager::ChessManImageManager()
    {
        if (NO_ERROR == loadimage(&_boardImage, "main.gif"))
        {
        }
        else
        {
            std::cerr << "Load Image Failed" << std::endl;
        }

        if (NO_ERROR == loadimage(&_chessManMaskImage, "mask.bmp"))
        {

        }
        else
        {
            std::cerr << "Load Image Failed" << std::endl;
        }

        //Draw Red Player Chess










        //LoadImage
        {
            IMAGE redRookImg;
            if (NO_ERROR == loadimage(&redRookImg, "red_rook.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::RED_SIDE;
                elem._manType = ChessMan_T::ROOK_MAN;
                elem._img = redRookImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {
            IMAGE redKnightImg;
            if (NO_ERROR == loadimage(&redKnightImg, "red_knight.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::RED_SIDE;
                elem._manType = ChessMan_T::KNIGHT_MAN;
                elem._img = redKnightImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }



        {
            IMAGE redBishopImg;
            if (NO_ERROR == loadimage(&redBishopImg, "red_bishop.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::RED_SIDE;
                elem._manType = ChessMan_T::BISHOP_MAN;
                elem._img = redBishopImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {
            IMAGE redQueenImg;
            if (NO_ERROR == loadimage(&redQueenImg, "red_queen.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::RED_SIDE;
                elem._manType = ChessMan_T::QUEEN_MAN;
                elem._img = redQueenImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {
            IMAGE redKingImg;
            if (NO_ERROR == loadimage(&redKingImg, "red_king.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::RED_SIDE;
                elem._manType = ChessMan_T::KING_MAN;
                elem._img = redKingImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {
            IMAGE redCannonImg;
            if (NO_ERROR == loadimage(&redCannonImg, "red_cannon.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::RED_SIDE;
                elem._manType = ChessMan_T::CANNON_MAN;
                elem._img = redCannonImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {
            IMAGE redPawnImg;
            if (NO_ERROR == loadimage(&redPawnImg, "red_pawn.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::RED_SIDE;
                elem._manType = ChessMan_T::PAWN_MAN;
                elem._img = redPawnImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }








        //LoadImage
        {
            IMAGE blackRookImg;
            if (NO_ERROR == loadimage(&blackRookImg, "black_rook.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::BLACK_SIDE;
                elem._manType = ChessMan_T::ROOK_MAN;
                elem._img = blackRookImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }
        {
            IMAGE blackKnightImg;
            if (NO_ERROR == loadimage(&blackKnightImg, "black_knight.bmp"))
            {

                ImageElem elem;
                elem._color = ChessColor::BLACK_SIDE;
                elem._manType = ChessMan_T::KNIGHT_MAN;
                elem._img = blackKnightImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }



        {
            IMAGE blackBishopImg;
            if (NO_ERROR == loadimage(&blackBishopImg, "black_bishop.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::BLACK_SIDE;
                elem._manType = ChessMan_T::BISHOP_MAN;
                elem._img = blackBishopImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }


        {
            IMAGE blackQueenImg;
            if (NO_ERROR == loadimage(&blackQueenImg, "black_queen.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::BLACK_SIDE;
                elem._manType = ChessMan_T::QUEEN_MAN;
                elem._img = blackQueenImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {
            IMAGE blackKingImg;
            if (NO_ERROR == loadimage(&blackKingImg, "black_king.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::BLACK_SIDE;
                elem._manType = ChessMan_T::KING_MAN;
                elem._img = blackKingImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {
            IMAGE blackCannonImg;
            if (NO_ERROR == loadimage(&blackCannonImg, "black_cannon.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::BLACK_SIDE;
                elem._manType = ChessMan_T::CANNON_MAN;
                elem._img = blackCannonImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }

        {

            IMAGE blackPawnImg;
            if (NO_ERROR == loadimage(&blackPawnImg, "black_pawn.bmp"))
            {
                ImageElem elem;
                elem._color = ChessColor::BLACK_SIDE;
                elem._manType = ChessMan_T::PAWN_MAN;
                elem._img = blackPawnImg;
                _imgArray.push_back(elem);
            }
            else
            {
                std::cerr << "Load Image Failed" << std::endl;
            }
        }
    }
