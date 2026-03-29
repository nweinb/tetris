#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BLOCK_HEIGHT 2
#define MIDDLE_BOARD (BOARD_WIDTH / 2)
#define NUM_BLOCK_TYPES 7
#define EMPTY_SPACE '*'
#define FULL_SPACE '#'

#define TEMP_SQUARE 99
#define EMPTY 0
#define LIGHT_BLUE 1
#define YELLOW 2
#define MAGENTA 3
#define GREEN 4
#define RED 5
#define DARK_BLUE 6
#define ORANGE 7

//TODO edgecase of bad param size

/*
* Creates a block template depending on type of block
* Param: block - return param that holds the created block
*/

bool square_block(uint32_t block[][BOARD_HEIGHT]);

bool t_block(uint32_t block[][BOARD_HEIGHT]);

bool line_block(uint32_t block[][BOARD_HEIGHT]);

bool z_left_block(uint32_t block[][BOARD_HEIGHT]);

bool z_right_block(uint32_t block[][BOARD_HEIGHT]);

bool l_left_block(uint32_t block[][BOARD_HEIGHT]);

bool l_right_block(uint32_t block[][BOARD_HEIGHT]);

/*
* Creates an empty block template
* Param: block - return param that holds the created block
*/

bool init_block(uint32_t block[][BOARD_HEIGHT]);

/*
* Generates a random block 
* Param: block - return param that holds the created block
*/
bool generate_block(uint32_t block[][BOARD_HEIGHT]);
