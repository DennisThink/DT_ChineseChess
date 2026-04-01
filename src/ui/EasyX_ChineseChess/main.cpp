#include "UI_ChessBoard.hpp"
int main(int argc, char* argv[])
{
    UI_ChessBoard game;
    game.StartGame();
    game.DoMainLoop();
    game.EndGame();
    return 0;
}