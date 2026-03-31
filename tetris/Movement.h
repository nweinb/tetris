#pragma once
#include <stdint.h>

#include "Blocks.h"
#include "Board.h"

/*
* Moves given block left one space
* Params: block - the position of the block to move
*		  board - the board the block is moved on
*/
bool move_block_left(Block* block, Board board);

/*
* Moves given block right one space
* Params: block - the position of the block to move
*		  board - the board the block is moved on
*/
bool move_block_right(Block* block, Board board);

/*
* Rotates given block clockwise
* Params: block - the position of the block to move
*/
bool rotate_clockwise(Block* block, Board board);

/*
* Rotates given block counter-clockwise
* Params: block - the position of the block to move
*/
bool rotate_counter_clockwise(Block* block, Board board);

/*
* Moves given block down one space
* Params: block - the block to move
*/
bool drop_block(Block* block);