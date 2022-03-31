#ifndef C_STATIC_LIB_MINESWEEPER_LIBRARY_H
#define C_STATIC_LIB_MINESWEEPER_LIBRARY_H

#if defined (__cplusplus)
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Error and Status Codes
*/

#define MAX_SIDE (15)
#define MAX_MINE (10)


typedef enum
{
    MS_LIB_STATUS_OK,
    MS_LIB_STATUS_INVALID_BOARD_SIZE,
    MS_LIB_STATUS_UNSUPPORTED_BOARD_SIZE,
    MS_LIB_STATUS_INVALID_MINE_CNT,
    MS_LIB_STATUS_INVALID_LOCATION,
    MS_LIB_STATUS_CELL_CLEARED_ALREADY,
    MS_LIB_STATUS_GAME_LOST,
    MS_LIB_STATUS_GAME_WON,
    MS_LIB_STATUS_INVALID_CMD,
    MS_LIB_STATUS_GAME_IN_POGRESS
}MS_LIB_STATUS_CODES;


typedef enum{
initial,
hasmine,
flagged,
cleared
}CellState;

typedef struct 
{
    CellState cellState;
    int x;
    int y;
    /* data */
    int adjMineCnt;
}Cell;


typedef struct
{
    unsigned int side;
    unsigned int mineCnt;
    unsigned int remainingMoves;
    Cell cells[MAX_SIDE*MAX_SIDE];
    Cell mines[MAX_MINE];
} Game;



const unsigned char * MS_getModuleVersion(void);
MS_LIB_STATUS_CODES MS_GenRandomMines();
MS_LIB_STATUS_CODES MS_GenUserProvidedMines( unsigned int minePositions[][2]);
void MS_getGameState(Game *destBoard);
MS_LIB_STATUS_CODES MS_executeGame(char command,unsigned int x , unsigned int y);
extern Cell getCellByCoordinates(int x , int y);
MS_LIB_STATUS_CODES MS_initGame(unsigned int mineCnt , unsigned int gameBoardSize);

#if defined (__cplusplus)
}
#endif

#endif

