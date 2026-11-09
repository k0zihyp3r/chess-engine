#pragma once

enum class PieceType {NONE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};
enum class Color {NONE, WHITE, BLACK};

struct Piece {
    PieceType type;
    Color color;
    char symbol;
};

class Board {
private:
    Piece board[8][8];
    bool isRookPathClear(int startX,  int startY, int endX, int endY) const;
    bool isRookMoveValid(int startX,  int startY, int endX, int endY) const;
public:
    Board();
    void setupDefaultBoard();
    void printBoard() const;
    bool movePiece(int startX, int startY, int endX, int endY);

};