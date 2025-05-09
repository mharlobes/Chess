#ifndef CHESS_H
#define CHESS_H
#include <wchar.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
  PAWN,
  ROOK,
  KNIGHT,
  BISHOP,
  QUEEN,
  KING,
  EMPTY
} pieceType;

typedef enum
{
  BLACK,
  WHITE,
  NONE
} pieceColor;

typedef enum
{
  WIN_WHITE,
  WIN_BLACK,
  DRAW,
  CONTINUE
} stateOfGame;

struct Piece
{
  pieceType piece;
  pieceColor color;
  int rank;
  int file;
};

struct Board
{
  struct Piece *board[8][8];
};

struct Move
{
  int x0;
  int y0;
  int x1;
  int y1;
};

struct Game
{
  stateOfGame gameState;
};

#endif