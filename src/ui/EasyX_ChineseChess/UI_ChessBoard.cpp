#include "UI_ChessBoard.hpp"
#include "ChessBoard.hpp"
#include "UI_ImageManager.hpp"
#include "chess_types.hpp"
#include <easyx.h>
#include <iostream>
static void drawChessMan(int x, int y, IMAGE* maskImage, IMAGE* chessImage)
{
    putimage(x, y, maskImage, SRCAND);
    putimage(x, y, chessImage, SRCPAINT);
}


static void drawCornerMarks(int x, int y, int pieceSize, int cornerLen, int lineWidth, COLORREF color)
{
    setlinecolor(color);
    setlinestyle(PS_SOLID, lineWidth);

    int smallCorner = cornerLen / 2;  // 可走位置的折角更小，以示区分

    // 左上角
    line(x, y, x + smallCorner, y);
    line(x, y, x, y + smallCorner);

    // 右上角
    line(x + pieceSize, y, x + pieceSize - smallCorner, y);
    line(x + pieceSize, y, x + pieceSize, y + smallCorner);

    // 左下角
    line(x, y + pieceSize, x + smallCorner, y + pieceSize);
    line(x, y + pieceSize, x, y + pieceSize - smallCorner);

    // 右下角
    line(x + pieceSize, y + pieceSize, x + pieceSize - smallCorner, y + pieceSize);
    line(x + pieceSize, y + pieceSize, x + pieceSize, y + pieceSize - smallCorner);
}
UI_ChessBoard::UI_ChessBoard()
{

}

void UI_ChessBoard::StartGame()
{

}

struct ChessPostion
{
    int _x;
    int _y;
};
void UI_ChessBoard::DoMainLoop()
{
    std::cout << "this is a Chinese Chess Program" << std::endl;
    initgraph(800, 800);	// 创建绘图窗口，大小为 640x480 像素

    IMAGE staticMemoryImg;
    IMAGE selectedMemoryImg;
    ChessManImageManager imageManager;
    ChessBoard boardManager;
    Resize(&staticMemoryImg, 800, 800);
    Resize(&selectedMemoryImg, 800, 800);
    SetWorkingImage(&staticMemoryImg);
    setbkcolor(BLACK);
    cleardevice();
    //circle(200, 200, 100);	// 画圆，圆心(200, 200)，半径 100
    int CHESS_CELL_WIDTH = 58;
    int CHESS_START_X = 20;
    int CHESS_START_Y = 20;
    //Draw staticMemoryImg
    {

        int chessX = CHESS_START_X;
        int chessY = CHESS_START_Y;
        IMAGE boardImage = imageManager.GetBoardImage();
        putimage(0, 0, &boardImage);
        ChessBoard board;
        board.SetBoardToStartState();
        int maxX = board.GetMaxX();
        int maxY = board.GetMaxY();
        IMAGE maskImage = imageManager.GetChessManMaskImage();
		const ChineseBoardData_T& boardData = board.GetBoardData();
        for (int x = 0; x < maxX; x++)
        {
            for (int y = 0; y < maxY; y++)
            {
                ChessManBoardElem elem = boardData._board[x][y];
                if (elem._color != ChessColor::NONE_SIDE && elem._manType != ChessMan_T::NONE_MAN)
                {
                    IMAGE chessManImg = imageManager.GetChessManImage(elem._color, elem._manType);
                    chessX = CHESS_START_X + CHESS_CELL_WIDTH * x;
                    chessY = CHESS_START_Y + CHESS_CELL_WIDTH * y;
                    drawChessMan(chessX, chessY, &maskImage, &chessManImg);
                }
            }
        }
    }

    SetWorkingImage(&selectedMemoryImg);
    putimage(0, 0, &staticMemoryImg);

    COLORREF color(RGB(255, 0, 0));
    ChessPostion selectedPos;
    selectedPos._x = 0;
    selectedPos._y = 0;
    int selectedChessX = CHESS_START_X+selectedPos._x * CHESS_CELL_WIDTH;
    int selectedChessY = CHESS_START_Y + selectedPos._y* CHESS_CELL_WIDTH;
    drawCornerMarks(selectedChessX, selectedChessY, 58, 15, 3, color);
    SetWorkingImage(NULL);
    bool bShowSelect = false;
    ExMessage msg;
    bool bMouseMsgHandle = true;
    while (true)
    {

        //HandleMessage
        do
        {
            peekmessage(&msg, EX_MOUSE | EX_KEY);
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
            {
                int mouseX = msg.x;
                int mouseY = msg.y;
                
                int x = (mouseX - CHESS_START_X) / CHESS_CELL_WIDTH;
                int y = (mouseY - CHESS_START_Y) / CHESS_CELL_WIDTH;
                
                ChessBoard board;
                int maxX = board.GetMaxX();
                int maxY = board.GetMaxY();
                if (x < maxX && y < maxY)
                {
                    int offSetX = mouseX - x * CHESS_CELL_WIDTH - CHESS_START_X;
                    int offSetY = mouseY - y * CHESS_CELL_WIDTH - CHESS_START_Y;
                    if (offSetX *1.1 < CHESS_CELL_WIDTH && offSetY * 1.1< CHESS_CELL_WIDTH)//Depends
                    {
                        selectedPos._x = x;
                        selectedPos._y = y;
                        {
                            SetWorkingImage(&selectedMemoryImg);
                            putimage(0, 0, &staticMemoryImg);

                            COLORREF color(RGB(255, 0, 0));
                            int selectedChessX = CHESS_START_X + selectedPos._x * CHESS_CELL_WIDTH;
                            int selectedChessY = CHESS_START_Y + selectedPos._y * CHESS_CELL_WIDTH;
                            drawCornerMarks(selectedChessX, selectedChessY, 58, 15, 3, color);
                            SetWorkingImage(NULL);
                            bMouseMsgHandle = false;
                        }
                    }
                }
            }break;
            default:
            {
                bMouseMsgHandle = false;
            }break;
            }
        } while (bMouseMsgHandle);
        bMouseMsgHandle = true;
        //DrawUI
        {
            SetWorkingImage(NULL);
            cleardevice();
            BeginBatchDraw();
            // 定时切换
            if (bShowSelect)
            {
                putimage(0, 0, &selectedMemoryImg);
                std::cout << "show selected Image" << std::endl;
            }
            else
            {
                putimage(0, 0, &staticMemoryImg);
                std::cout << "show staticImage Image" << std::endl;
            }
            bShowSelect = !bShowSelect;
            EndBatchDraw();
            Sleep(15);
        }
    }
    //Draw Black Player Chess
    //_getch();				// 按任意键继续
    closegraph();			// 关闭绘图窗口
    std::cout << "this is a Chinese Chess program" << std::endl;
    ChessBoard board;
    board.printBoard();
    int choice = 0;
    std::cin >> choice;
}

void UI_ChessBoard::EndGame()
{

}