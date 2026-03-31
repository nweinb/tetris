#include "Blocks.h"

bool generate_block(Block* block) {
	if (!init_block(block)) {
		return false;
	}

	srand(time(NULL));
	int r = rand() % NUM_BLOCK_TYPES;
	switch (r) {
		case SQUARE:
			return square_block(block);
		case T_BLOCK:
			return t_block(block);
		case LINE:
			return line_block(block);
		case Z_LEFT:
			return z_left_block(block);
		case Z_RIGHT:
			return z_right_block(block);
		case L_LEFT:
			return l_left_block(block);
		case L_RIGHT:
			return l_right_block(block);
		default:
			return false;
	}
}

bool square_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	block->shape[1][1] = YELLOW;
	block->shape[1][2] = YELLOW;
	block->shape[2][1] = YELLOW;
	block->shape[2][2] = YELLOW;
	return true;
}

bool t_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	block->shape[0][2] = MAGENTA;
	block->shape[1][1] = MAGENTA;
	block->shape[1][2] = MAGENTA;
	block->shape[2][2] = MAGENTA;
	return true;
}

bool line_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	block->shape[0][1] = LIGHT_BLUE;
	block->shape[1][1] = LIGHT_BLUE;
	block->shape[2][1] = LIGHT_BLUE;
	block->shape[3][1] = LIGHT_BLUE;
	return true;
}

bool z_left_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	block->shape[0][1] = GREEN;
	block->shape[1][1] = GREEN;
	block->shape[1][2] = GREEN;
	block->shape[2][2] = GREEN;
	return true;
}

bool z_right_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	block->shape[1][2] = RED;
	block->shape[2][1] = RED;
	block->shape[2][2] = RED;
	block->shape[3][1] = RED;
	return true;
}

bool l_left_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	block->shape[0][1] = DARK_BLUE;
	block->shape[0][2] = DARK_BLUE;
	block->shape[1][2] = DARK_BLUE;
	block->shape[2][2] = DARK_BLUE;
	return true;
}

bool l_right_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	block->shape[1][2] = ORANGE;
	block->shape[2][2] = ORANGE;
	block->shape[3][1] = ORANGE;
	block->shape[3][2] = ORANGE;
	return true;
}

bool init_block(Block* block) {
	if (block == NULL || block->shape == NULL) {
		return false;
	}
	for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
		for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
			block->shape[column][row] = EMPTY;
		}
	}
	return true;
}

bool print_block(HANDLE screen_handle, Block* block) {
	if (block == NULL || block->position == NULL || block->shape == NULL) {
		return false;
	}

	for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
		for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
			if (block->shape[column][row] != EMPTY) {
				if (!print_square(block->shape[column][row], block->position[X_POS] + column, block->position[Y_POS] + row, screen_handle)) {
					return false;
				}
			}
		}
	}
	return true;
}