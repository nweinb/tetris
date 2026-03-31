#include "GameLoop.h"

bool game_loop(HANDLE screen_handle) {
	Board board = { {EMPTY} };
	Block block = {
		{ {EMPTY} },
		{ EMPTY }
	};

	uint8_t res;
	int32_t score = 5;
	bool has_block = false;
	while (true) {
		res = wait_for_input(screen_handle, board, &block, &has_block, &score);
		if (res == GAME_END) {
			break;
		}
		else if (res == FAILURE) {
			return false;
		}
		res = handle_input(_getch(), board, &block);
		if (res == GAME_END) {
			break;
		}
		else if (res == FAILURE) {
			return false;
		}
	}
	printf("Game over!\nScore: %d\n", score);
	return true;
} 

uint8_t handle_input(char input, Board board, Block* block) {
	if (board == NULL || block == NULL) {
		return FAILURE;
	}

	switch (input) {
	case QUIT:
		return GAME_END;
	case LEFT:
		if (!move_block_left(block, board) || update_board(board, *block) == FAILURE) {
			print_error("moving block");
			return FAILURE;
		}
		return SUCCESS;
	case RIGHT:
		if (!move_block_right(block, board) || update_board(board, *block) == FAILURE) {
			print_error("moving block");
			return FAILURE;
		}
		return SUCCESS;
	case ROTATE_CLOCKWISE:
		if (!rotate_clockwise(block, board) || update_board(board, *block) == FAILURE) {
			print_error("rotating block");
			return FAILURE;
		}
		return SUCCESS;
	case ROTATE_COUNTER_CLOCKWISE:
		if (!rotate_counter_clockwise(block, board) || update_board(board, *block) == FAILURE) {
			print_error("rotating block");
			return FAILURE;
		}
		return SUCCESS;
	}
	return SUCCESS;
}

uint8_t wait_for_input(HANDLE screen_handle, Board board, Block* block, bool* has_block, int32_t* score) {
	if (board == NULL || block == NULL || has_block == NULL || score == NULL || *score == 0) {
		return FAILURE;
	}

	uint32_t sleep_time_ms;
	while (!_kbhit()) {
		if (START_SPEED - (*score / DIFFICULTY_MULTIPLIER) > MAX_SPEED) {
			sleep_time_ms = START_SPEED - (*score / DIFFICULTY_MULTIPLIER);
		}
		else {
			sleep_time_ms = MAX_SPEED;
		}
		if (!*has_block) {
			if (!spawn_block_to_board(board, block)) {
				print_error("spawning block");
				return FAILURE;
			}
			*has_block = true;
		}
		else {
			Sleep(sleep_time_ms);
			if (!drop_block(block)) {
				print_error("dropping block");
				return FAILURE;
			}
			uint8_t res = update_board(board, *block);
			if (res == BLOCK_HIT) {
				if (!check_full_line(board, score)) {
					return FAILURE;
				}
				*has_block = false;
			}
			else if (res == GAME_END) {
				return GAME_END;
			}
			else if (res == FAILURE) {
				print_error("updating board");
				return FAILURE;
			}
		}
		if (!print_board(screen_handle, board) || !print_block(screen_handle, block)) {
			print_error("printing board");
			return FAILURE;
		}
		*score += 5;
	}
	return SUCCESS;
}