#include "GameLoop.h"

bool game_loop(HANDLE screen_handle) {
	uint32_t board[BOARD_WIDTH][BOARD_HEIGHT];
	uint32_t block_position[BOARD_WIDTH][BOARD_HEIGHT];
	if (!init_board(board)) {
		print_error("initializing board");
		return false;
	}
	bool quit = false;
	char input = ' ';
	bool has_block = false;
	while (!quit) {
		while (!_kbhit()) {
			if (!has_block) {
				if (!spawn_block_to_board(board, block_position)) {
					print_error("spawning block");
					return false;
				}
				has_block = true;
			}
			else {
				if (!drop_block(block_position) || !update_board(board, block_position)) {
					print_error("dropping block");
					return false;
				}
			}
			if (!print_board(screen_handle, board)) {
				print_error("printing board");
				return false;
			}
			Sleep(SLEEP_TIME_MS);

		}
		input = _getch();
		switch (input) {
			case QUIT:
				quit = true;
				break;
			case LEFT:
				move_block_left(block_position);
				update_board(board, block_position);
				break;
			case RIGHT:
				move_block_right(block_position);
				update_board(board, block_position);
				break;
		}
	}
	return true;
} 