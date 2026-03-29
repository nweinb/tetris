#include "Movement.h"

bool move_block_left(uint32_t block_position[][BOARD_HEIGHT]) {
	if (block_position == NULL) {
		return false;
	}

	if (block_position[0][0] != EMPTY || block_position[0][BLOCK_HEIGHT - 1] != EMPTY) {
		return true;
	}

	for (uint32_t row = 0; row < BOARD_HEIGHT; row++) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			if (column - 1 >= 0 && block_position[column][row] != EMPTY) {
				block_position[column - 1][row] = block_position[column][row];
				block_position[column][row] = TEMP_SQUARE;
			}
		}
	}
	return true;
}

bool move_block_right(uint32_t block_position[][BOARD_HEIGHT]) {
	if (block_position == NULL) {
		return false;
	}

	if (block_position[BOARD_WIDTH - 1][0] != EMPTY || block_position[BOARD_WIDTH - 1][BLOCK_HEIGHT - 1] != EMPTY) {
		return true;
	}

	for (uint32_t row = 0; row < BOARD_HEIGHT; row++) {
		for (int32_t column = BOARD_WIDTH - 1; column >= 0; column--) {
			if (column + 1 < BOARD_WIDTH && block_position[column][row] != EMPTY) {
				block_position[column + 1][row] = block_position[column][row];
				block_position[column][row] = TEMP_SQUARE;
			}
		}
	}
	return true;
}

bool drop_block(uint32_t block_position[][BOARD_HEIGHT]) {
	if (block_position == NULL) {
		return false;
	}

	for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
		if (block_position[column][BOARD_HEIGHT - 1] != EMPTY) {
			return true;
		}
	}

	for (int32_t row = BOARD_HEIGHT - 1; row >= 0; row--) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			if (block_position[column][row] != EMPTY) {
				block_position[column][row + 1] = block_position[column][row];
				block_position[column][row] = TEMP_SQUARE;
			}
		}
	}
	return true;
}

