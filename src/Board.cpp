#include "Board.hpp"
#include <iostream>

Board::Board(){
    setupDefaultBoard();
}

bool Board::isRookPathClear(int startX,  int startY, int endX, int endY) const{
    if(startX == endX){
        if(endY> startY){
            startY++;
            for(int i = startY; i < endY; i++){
                if (board[i][startX].type != PieceType::NONE) {
                    return false;
                }
            }
        } else {
            startY--;
            for(int i = endY; i > startY; i--){
                if (board[i][startX].type != PieceType::NONE) {
                    return false;
                }
            }
        }
    } else if(startY == endY) {
        if(endX > startX){
            startX++;
            for(int i = startX; i < endX; i++){
                if (board[startY][i].type != PieceType::NONE) {
                    return false;
                }
            }
        } else {
            startX--;
            for(int i = endX; i > startX; i--){
                if (board[startY][i].type != PieceType::NONE) {
                    return false;
                }
            }
        }
    }
    else {
        return false;
    }
    
    return true;
}

bool Board::isRookMoveValid(int startX,  int startY, int endX, int endY) const{
    if(startX != endX && startY != endY){
        return false;
    }

    Color currentColor = board[startY][startX].color;
    Color enemyColor = board[endY][endX].color;

    if(currentColor == enemyColor){
        return false;
    }

    if(!isRookPathClear(startX, startY, endX, endY)){
        return false;
    }

    return true;
}

//bool Board::isPawnMoveValid(){}


void Board::setupDefaultBoard(){
    for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                board[row][col] = {PieceType::NONE, Color::NONE, '.'};
            }
        }
    
    for (int col = 0; col < 8; col++) {
        board[1][col] = {PieceType::PAWN, Color::BLACK, 'p'};
        board[6][col] = {PieceType::PAWN, Color::WHITE, 'P'};
    }

    PieceType backRowPieces[8] = {
        PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
        PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK

    };
    char blackSymbols[8] = { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' };
    char whiteSymbols[8] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };

    for (int col = 0; col < 8; col++) {
        board[0][col] = {backRowPieces[col], Color::BLACK, blackSymbols[col]};
        board[7][col] = {backRowPieces[col], Color::WHITE, whiteSymbols[col]};
    }

}

void Board::printBoard() const {
std::cout << "\n  a b c d e f g h\n";
    for (int row = 0; row < 8; row++) {
        std::cout << 8 - row << " ";
        for (int col = 0; col < 8; col++) {
            std::cout << board[row][col].symbol << " ";
        }
        std::cout << 8 - row << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
}

bool Board::movePiece(int startX, int startY, int endX, int endY){
    
    if (startX < 0 || startX > 7 || startY < 0 || startY > 7 ||
        endX < 0 || endX > 7 || endY < 0 || endY > 7) {
        return false;
    }
    Piece& sourcePiece = board[startY][startX];
    if(sourcePiece.type == PieceType::NONE){
        return false;
    }

    bool isLegal = false;
    switch (sourcePiece.type){
        case PieceType::ROOK:
            isLegal = isRookMoveValid(startX, startY, endX, endY);
            break;
        default:
            isLegal = false;
    }

    if(!isLegal){
        return false;
    }

    board[endY][endX] = sourcePiece;
    board[startY][startX] = {PieceType::NONE, Color::NONE, '.'};
    
    return true;
}