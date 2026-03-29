#include "Board.h"

bool print_board(HANDLE screen_handle, uint32_t board[][BOARD_HEIGHT]) {
	if (board == NULL) {
		return false;
	}

	COORD charBufSize = { 1, 1 };
	COORD characterPos = { 0, 0 };
	for (uint32_t row = 0; row < BOARD_HEIGHT; row++) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			SMALL_RECT writeArea = { column + 1, row, column + 1, row };
			switch (board[column][row]) {
				case EMPTY:
					if (!WriteConsoleOutput(screen_handle, gray(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				case LIGHT_BLUE:
					if (!WriteConsoleOutput(screen_handle, light_blue(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				case YELLOW:
					if (!WriteConsoleOutput(screen_handle, yellow(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				case MAGENTA:
					if (!WriteConsoleOutput(screen_handle, magenta(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				case GREEN:
					if (!WriteConsoleOutput(screen_handle, green(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				case RED:
					if (!WriteConsoleOutput(screen_handle, red(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				case DARK_BLUE:
					if (!WriteConsoleOutput(screen_handle, dark_blue(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				case ORANGE:
					if (!WriteConsoleOutput(screen_handle, orange(), charBufSize, characterPos, &writeArea)) {
						print_last_error("printing grid");
						return false;
					}
					break;
				default:
					return false;
			}
		}
	}
	return true;
}

bool init_board(uint32_t board[][BOARD_HEIGHT]) {
	if (board == NULL) {
		return false;
	}

	for (uint32_t row = 0; row < BOARD_HEIGHT; row++) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			board[column][row] = EMPTY;
		}
	}
	return true;
}

bool spawn_block_to_board(uint32_t board[][BOARD_HEIGHT], uint32_t block_position[][BOARD_HEIGHT]) {
	if (board == NULL || block_position == NULL) {
		return false;
	}

	if (!generate_block(block_position)) {
		return false;
	}

	return update_board(board, block_position);
}

bool update_board(uint32_t board[][BOARD_HEIGHT], uint32_t block_position[][BOARD_HEIGHT]) {
	if (board == NULL || block_position == NULL) {
		return false;
	}

	for (uint32_t row = 0; row < BOARD_HEIGHT; row++) {
		for (uint32_t column = 0; column < BOARD_WIDTH; column++) {
			if (block_position[column][row] != EMPTY) {
				if (block_position[column][row] == TEMP_SQUARE) {
					board[column][row] = EMPTY;
					block_position[column][row] = EMPTY;
				}
				else if (board[column][row] == EMPTY) {
						board[column][row] = block_position[column][row];
				}
			}
		}
	}
	return true;
}