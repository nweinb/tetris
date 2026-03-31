#pragma once
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>
#include <stdio.h>
#include <stdint.h>

#include "Board.h"
#include "Errors.h"
#include "Movement.h"
#include "EnumCodes.h"

// Starting speed, difficulty multipler, & max speed (Lower is faster)
#define START_SPEED 500
#define DIFFICULTY_MULTIPLIER 50
#define MAX_SPEED 75

#define QUIT 'q'
#define LEFT 'a'
#define RIGHT 'd'
#define ROTATE_CLOCKWISE 's'
#define ROTATE_COUNTER_CLOCKWISE 'w'

/*
* Starts game loop
* Params: screen_handle - screen to play on
*/
bool game_loop(HANDLE screen_handle);

/*
* Handles input logic
* Params: input - input char
*		  board - game board
*		  block - current active block
* Returns: 0 - Success
*		   1 - Error
*		   3 - Game end
*/
uint8_t handle_input(char input, Board board, Block* block);

/*
* Handles logic while waiting for input
* Params: screen_handle - screen to play on
*		  board - game board
*		  block - current active block
*		  has_block - if there is an active block
* Returns: 0 - Success
*		   1 - Error
*		   3 - Game end
*/
uint8_t wait_for_input(HANDLE screen_handle, Board board, Block* block, bool* has_block, int32_t* score);