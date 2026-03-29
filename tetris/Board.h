#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#include "Colors.h"
#include "Blocks.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define EMPTY_SPACE '*'
#define FULL_SPACE '#'

//TODO edgecases

/*
* Prints board to output stream
* Params: screen_handle - screen to print to
*		  board - board to print
*/
bool print_board(HANDLE screen_handle, uint32_t board[][BOARD_HEIGHT]);

/*
* Intitates an empty board
* Params: board - return param of created board
*/
bool init_board(uint32_t board[][BOARD_HEIGHT]);

/*
* Spawns a block to the board
* Params: board - board to spawn to
*		  block_position - return param of created block
*/
bool spawn_block_to_board(uint32_t board[][BOARD_HEIGHT], uint32_t block_position[][BOARD_HEIGHT]);

/*
* Updates the board with given block position
* Params: board - board update
*		  block_position - block that updates
*/
bool update_board(uint32_t board[][BOARD_HEIGHT], uint32_t block_position[][BOARD_HEIGHT]);