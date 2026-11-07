#include "Board.hpp"
#include <iostream>

Board::Board(){
    setupDefaultBoard();
}

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
    for (int row = 0; row < 8; ++row) {
        std::cout << 8 - row << " ";
        for (int col = 0; col < 8; ++col) {
            std::cout << board[row][col].symbol << " ";
        }
        std::cout << 8 - row << "\n";
    }
    std::cout << "  a b c d e f g h\n\n";
}

bool Board::movePiece(int startX, int startY, int endX, int endY){
    return true;
}