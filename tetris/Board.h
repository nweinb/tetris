#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#include "Colors.h"
#include "Blocks.h"
#include "EnumCodes.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

//TODO fix dragging blocks
 
typedef uint8_t Board[BOARD_WIDTH][BOARD_HEIGHT];

/*
* Prints board to output stream
* Params: screen_handle - screen to print to
*		  board - board to print
*/
bool print_board(HANDLE screen_handle, Board board);

/*
* Spawns a block to the board
* Params: board - board to spawn to
*		  block - return param of created block
*/
bool spawn_block_to_board(Board board, Block* block);

/*
* Updates the board with given block position
* Params: board - board update
*		  block - block that updates
* Returns: 0 - Success
*		   1 - Error
*		   2 - Block hit object
*		   3 - Game end
*/
uint8_t update_board(Board board, Block block);

/*
* Updates the board with given block position
* Params: board - board update
*		  block - block that updates
* Returns: 0 - Success
*		   1 - Error
*		   2 - Block hit object
*/
uint8_t check_for_hit(Board board, Block block);

/*
* Checks if a line is full on  the board
* Params: board - board that gets checked
*		  score - player's score
*/
bool check_full_line(Board board, int32_t* score);

/*
* Clears given row on the board and drops subsequent blocks
* Params: board - board that gets checked
*		  row_to_clear - the row to clear
*/
bool clear_line(Board board, int32_t row_to_clear);
