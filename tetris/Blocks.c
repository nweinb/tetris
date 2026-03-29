#include "Blocks.h"

bool generate_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL || !init_block(block)) {
		return false;
	}

	srand(time(NULL));
	int r = rand() % NUM_BLOCK_TYPES;
	switch (r) {
		case 0:
			return square_block(block);
		case 1:
			return t_block(block);
		case 2:
			return line_block(block);
		case 3:
			return z_left_block(block);
		case 4:
			return z_right_block(block);
		case 5:
			return l_left_block(block);
		case 6:
			return l_right_block(block);
		default:
			return false;
	}
}

bool square_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	block[MIDDLE_BOARD - 1][0] = YELLOW;
	block[MIDDLE_BOARD - 1][1] = YELLOW;
	block[MIDDLE_BOARD][0] = YELLOW;
	block[MIDDLE_BOARD][1] = YELLOW;
	return true;
}

bool t_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	block[MIDDLE_BOARD - 1][1] = MAGENTA;
	block[MIDDLE_BOARD][0] = MAGENTA;
	block[MIDDLE_BOARD][1] = MAGENTA;
	block[MIDDLE_BOARD + 1][1] = MAGENTA;
	return true;
}

bool line_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	block[MIDDLE_BOARD - 2][0] = LIGHT_BLUE;
	block[MIDDLE_BOARD - 1][0] = LIGHT_BLUE;
	block[MIDDLE_BOARD][0] = LIGHT_BLUE;
	block[MIDDLE_BOARD + 1][0] = LIGHT_BLUE;
	return true;
}

bool z_left_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	block[MIDDLE_BOARD - 2][0] = GREEN;
	block[MIDDLE_BOARD - 1][0] = GREEN;
	block[MIDDLE_BOARD - 1][1] = GREEN;
	block[MIDDLE_BOARD][1] = GREEN;
	return true;
}

bool z_right_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	block[MIDDLE_BOARD][1] = RED;
	block[MIDDLE_BOARD][0] = RED;
	block[MIDDLE_BOARD - 1][1] = RED;
	block[MIDDLE_BOARD + 1][0] = RED;
	return true;
}

bool l_left_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	block[MIDDLE_BOARD - 2][0] = DARK_BLUE;
	block[MIDDLE_BOARD - 2][1] = DARK_BLUE;
	block[MIDDLE_BOARD - 1][1] = DARK_BLUE;
	block[MIDDLE_BOARD][1] = DARK_BLUE;
	return true;
}

bool l_right_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	block[MIDDLE_BOARD - 1][1] = ORANGE;
	block[MIDDLE_BOARD][1] = ORANGE;
	block[MIDDLE_BOARD + 1][0] = ORANGE;
	block[MIDDLE_BOARD + 1][1] = ORANGE;
	return true;
}

bool init_block(uint32_t block[][BOARD_HEIGHT]) {
	if (block == NULL) {
		return false;
	}
	for (uint32_t row = 0; row < BOARD_HEIGHT; row++) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			block[column][row] = EMPTY;
		}
	}
	return true;
}