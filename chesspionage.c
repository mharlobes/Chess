#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chess.h"
#include "AI.h"
#include "checkmate.h"
#include "GUI.h"
#include "moveLog.h"
#include "movelogic.h"
#include "rules.h"

void initializeBoard(struct Board *board);
void printBoard(struct Board *board);
void movePiece(struct Move *move, struct Board *board);


int main()
{
  /* Structs, Variables & strings */
  struct Board b;
  struct Move m;
  // struct Piece inputPiece;

  int status = 1;
  /* Initialize Board */
  initializeBoard(&b);

  while (true)
  {
    // Print Board
    printf("\n");
    printBoard(&b);
    bool validInput = false;
    // While loop prompts for move
    while (!validInput)
    {
      printf("Enter the coordinates of the piece to move (x0 y0): ");
      scanf("%d %d", &m.x0, &m.y0);

      struct Piece *piece = b.board[m.y0 - 1][m.x0 - 1];

      printf("Piece at square [%d, %d]: ", m.x0, m.y0);
      switch (piece->piece)
      {
      case PAWN:
        switch (piece->color)
        {
        case WHITE:
          printf("WHITE ");
          break;
        case BLACK:
          printf("BLACK ");
          break;
        case NONE:
          printf("NONE");
          break;
        }
        printf("PAWN\n");
        break;
      case ROOK:
        switch (piece->color)
        {
        case WHITE:
          printf("WHITE ");
          break;
        case BLACK:
          printf("BLACK ");
          break;
        case NONE:
          printf("NONE\n");
          break;
        }
        printf("ROOK\n");
        break;
      case KNIGHT:
        switch (piece->color)
        {
        case WHITE:
          printf("WHITE ");
          break;
        case BLACK:
          printf("BLACK ");
          break;
        case NONE:
          printf("NONE\n");
          break;
        }
        printf("KNIGHT\n");
        break;
      case BISHOP:
        switch (piece->color)
        {
        case WHITE:
          printf("WHITE ");
          break;
        case BLACK:
          printf("BLACK ");
          break;
        case NONE:
          printf("NONE\n");
          break;
        }
        printf("BISHOP\n");
        break;
      case QUEEN:
        switch (piece->color)
        {
        case WHITE:
          printf("WHITE ");
          break;
        case BLACK:
          printf("BLACK ");
          break;
        case NONE:
          printf("NONE\n");
          break;
        }
        printf("QUEEN\n");
        break;
      case KING:
        switch (piece->color)
        {
        case WHITE:
          printf("WHITE ");
          break;
        case BLACK:
          printf("BLACK ");
          break;
        case NONE:
          printf("NONE\n");
          break;
        }
        printf("KING\n");
        break;
      case EMPTY:
        printf("EMPTY\n");
        break;
      default:
        printf("UNKNOWN\n");
        break;
      }

      if (m.x0 < 1 || m.x0 > 8 || m.y0 < 1 || m.y0 > 8)
      {
        printf("Invalid coordinates.\n");
        continue;
      }

      if (piece->color == NONE && piece->piece == EMPTY)
      {
        printf("No piece at that square\n");
        continue;
      }

      if (status == 1 && piece->color == BLACK)
      {
        printf("Not your piece!\n");
        continue;
      }

      if (status == 2 && piece->color == WHITE)
      {
        printf("Not your piece!\n");
        continue;
      }

      validInput = true;
    }

    printf("Enter the coordinates of the destination (x1 y1): ");
    scanf("%d %d", &m.x1, &m.y1);

    if (m.x1 < 1 || m.x1 > 8 || m.y1 < 1 || m.y1 > 8)
    {
      printf("Can't put a piece there.\n");
      continue;
    }

    movePiece(&m, &b);

    // isCheck();
    struct Game *game;

    if (status == 1)
    {
      printf("\nIt's the Black Player's turn.\n");
      status = 2;
    }
    else if (status == 2)
    {
      printf("\nIt's the White Player's turn.\n");
      status = 1;
    }

    if (status == 3)
    {
      if (game->gameState == WIN_BLACK)
      {
        printf("Black Has Won!\n");
      }

      else if (game->gameState == WIN_WHITE)
      {
        printf("White Has Won!\n");
      }
    }
  }

  return 0;
}
