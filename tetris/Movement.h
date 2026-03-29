#include <stdint.h>

#include "Blocks.h"

//TODO need to fix stop at walls

/*
* Moves given block left one space
* Params: block_position - the position of the block to move
*/
bool move_block_left(uint32_t block_position[][BOARD_HEIGHT]);

/*
* Moves given block right one space
* Params: block_position - the position of the block to move
*/
bool move_block_right(uint32_t block_position[][BOARD_HEIGHT]);

/*
* Moves given block down one space
* Params: block_position - the position of the block to move
*/
bool drop_block(uint32_t block_position[][BOARD_HEIGHT]);