#include "Board.h"

bool print_board(HANDLE screen_handle, Board board) {
	if (board == NULL) {
		return false;
	}

	for (uint32_t row = 0; row < BOARD_HEIGHT; row++) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			if (!print_square(board[column][row], column, row, screen_handle)) {
				return false;
			}
		}
	}
	return true;
}

bool spawn_block_to_board(Board board, Block* block) {
	if (board == NULL || block == NULL || block->position == NULL) {
		return false;
	}

	if (!generate_block(block)) {
		return false;
	}

	block->position[X_POS] = BOARD_WIDTH / 2 - BLOCK_WIDTH / 2;
	block->position[Y_POS] = 0;
}

uint8_t update_board(Board board, Block block) {
	if (board == NULL || block.position == NULL || block.shape == NULL) {
		return FAILURE;
	}

	uint8_t hit = check_for_hit(board, block);
	if (hit == BLOCK_HIT) {
		for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
			for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
				if (block.shape[column][row] != EMPTY) {
					board[block.position[X_POS] + column][block.position[Y_POS] + row] = block.shape[column][row];
				}
			}
		}
		if (block.position[Y_POS] <= 1) {
			return GAME_END;
		}
	}
	return hit;
}

uint8_t check_for_hit(Board board, Block block) {
	if (board == NULL || block.position == NULL || block.shape == NULL) {
		return FAILURE;
	}

	for (uint32_t row = 0; row < BLOCK_HEIGHT; row++) {
		for (uint32_t column = 0; column < BLOCK_WIDTH; column++) {
			if (block.shape[column][row] != EMPTY) {
				if (block.position[Y_POS] + row + 1 == BOARD_HEIGHT || board[block.position[X_POS] + column][block.position[Y_POS] + row + 1] != EMPTY) {
					return BLOCK_HIT;
				}
			}
		}
	}
	return SUCCESS;
}

bool check_full_line(Board board, int32_t* score) {
	if (board == NULL || score == NULL) {
		return false;
	}

	for (int32_t row = BOARD_HEIGHT - 1; row >= 0; row--) {
		bool full_row = true;
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			if (board[column][row] == EMPTY) {
				full_row = false;
				break;
			}
		}
		if (full_row) {
			*score += 1000;
			if (!clear_line(board, row) || !check_full_line(board, score)) {
				return false;
			}
		}
	}
	return true;
}

bool clear_line(Board board, int32_t row_to_clear) {
	if (board == NULL) {
		return false;
	}

	for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
		board[column][row_to_clear] = EMPTY;
	}

	for (int32_t row = row_to_clear--; row >= 0; row--) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			board[column][row + 1] = board[column][row];
		}
	}
	return true;
}