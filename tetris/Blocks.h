#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "Colors.h"
#include "EnumCodes.h"

#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 4
#define NUM_BLOCK_TYPES 7

#define X_POS 0
#define Y_POS 1

typedef struct Block {
	uint8_t shape[BLOCK_WIDTH][BLOCK_HEIGHT];
	int16_t position[2];
} Block;

/*
* Creates a block template depending on type of block
* Param: block - return param that holds the created block
*/

bool square_block(Block* block);

bool t_block(Block* block);

bool line_block(Block* block);

bool z_left_block(Block* block);

bool z_right_block(Block* block);

bool l_left_block(Block* block);

bool l_right_block(Block* block);

/*
* Creates an empty block template
* Param: block - return param that holds the created block
*/

bool init_block(Block* block);

/*
* Generates a random block 
* Param: block - return param that holds the created block
*/
bool generate_block(Block* block);

/*
* Prints block to output stream
* Params: screen_handle - screen to print to
*		  block - block to print
*/
bool print_block(HANDLE screen_handle, Block* block);