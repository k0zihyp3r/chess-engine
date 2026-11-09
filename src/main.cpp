#include <iostream>
#include "../include/Board.hpp"

int main(){
    Board board;
    board.printBoard();
    board.movePiece(7,6,7,5);
    board.printBoard();
    board.movePiece(7,7,7,6);
    board.printBoard();
    board.movePiece(7,6,7,5);
    board.printBoard();
    //board.movePiece();
    return 0;
}