#include "Movement.h"

bool move_block_left(Block* block, Board board) {
	if (board == NULL || block == NULL || block->position == NULL || block->shape == NULL) {
		return false;
	}

	for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
		for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
			if (block->shape[column][row] != EMPTY) {
				if (column + block->position[X_POS] <= 0 || board[column + block->position[X_POS] - 1][row + block->position[Y_POS]] != EMPTY) {
					return true;
				}
			}
		}
	}
	block->position[X_POS]--;
	return true;
}

bool move_block_right(Block* block, Board board) {
	if (board == NULL || block == NULL || block->position == NULL || block->shape == NULL) {
		return false;
	}

	for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
		for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
			if (block->shape[column][row] != EMPTY) {
				if (column + block->position[X_POS] + 1 >= BOARD_WIDTH || board[column + block->position[X_POS] + 1][row + block->position[Y_POS]] != EMPTY) {
					return true;
				}
			}
		}
	}
	block->position[X_POS]++;
	return true;
}

bool rotate_clockwise(Block* block, Board board) {
	if (board == NULL || block == NULL || block->position == NULL || block->shape == NULL) {
		return false;
	}

	for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
		for (uint32_t row = 0; row < BLOCK_HEIGHT / 2; row++) {
			uint8_t temp = block->shape[column][row];
			block->shape[column][row] = block->shape[column][BLOCK_WIDTH - row - 1];
			block->shape[column][BLOCK_WIDTH - row - 1] = temp;
		}
	}
	for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
		for (uint32_t row = column + 1; row < BLOCK_HEIGHT; row++) {
			uint8_t temp = block->shape[column][row];
			block->shape[column][row] = block->shape[row][column];
			block->shape[row][column] = temp;
		}
	}

	for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
		for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
			if (block->shape[column][row] != EMPTY) {
				if (column + block->position[X_POS] >= BOARD_WIDTH || column + block->position[X_POS] < 0
					|| board[column + block->position[X_POS]][row + block->position[Y_POS]] != EMPTY) {
					return rotate_counter_clockwise(block, board);
				}
			}
		}
	}
	return true;
}


bool rotate_counter_clockwise(Block* block, Board board) {
	if (block == NULL || block->position == NULL || block->shape == NULL) {
		return false;
	}

	for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
		for (uint32_t row = column + 1; row < BLOCK_HEIGHT; row++) {
			uint8_t temp = block->shape[column][row];
			block->shape[column][row] = block->shape[row][column];
			block->shape[row][column] = temp;
		}
	}
	for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
		for (uint32_t row = 0; row < BLOCK_HEIGHT / 2; row++) {
			uint8_t temp = block->shape[column][row];
			block->shape[column][row] = block->shape[column][BLOCK_HEIGHT - row - 1];
			block->shape[column][BLOCK_HEIGHT - row - 1] = temp;
		}
	}

	for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
		for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
			if (block->shape[column][row] != EMPTY) {
				if (column + block->position[X_POS] >= BOARD_WIDTH || column + block->position[X_POS] < 0
					|| board[column + block->position[X_POS]][row + block->position[Y_POS]] != EMPTY) {
					return rotate_clockwise(block, board);
				}
			}
		}
	}
	return true;
}
bool drop_block(Block* block) {
	if (block == NULL || block->position == NULL) {
		return false;
	}
	
	block->position[Y_POS]++;
	return true;
}

