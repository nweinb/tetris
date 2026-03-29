#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdbool.h>

// Doesn't actually have to be exact, just not too big
#define CONSOLE_WIDTH 10
#define CONSOLE_HEIGHT 20

/**
* Convert the last Windows error to string and print
*/
static void print_last_error(const char* context);

/**
* Run the game in a loop until the user loses or exits
*/
static bool game_loop(HANDLE screen_handle);

int main() {
	HANDLE screen_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE == screen_handle) {
		print_last_error("opening handle to console");
		return 1;
	}

	// Make anything printed to the console appear below the game screen
	const COORD cursor_position = { .Y = CONSOLE_HEIGHT, .X = 0 };
	if (!SetConsoleCursorPosition(screen_handle, cursor_position)) {
		print_last_error("setting cursor position");
		return 1;
	}

	CONSOLE_CURSOR_INFO original_cursor_info;
	if (!GetConsoleCursorInfo(screen_handle, &original_cursor_info)) {
		print_last_error("getting cursor info");
		return 1;
	}

	const CONSOLE_CURSOR_INFO cursor_info = { .dwSize =
	original_cursor_info.dwSize, .bVisible = FALSE };
	if (!SetConsoleCursorInfo(screen_handle, &cursor_info)) {
		print_last_error("hiding blinking cursor");
		return 1;
	}

	bool successful = game_loop(screen_handle);
	// Restore original cursor
	if (!SetConsoleCursorInfo(screen_handle, &original_cursor_info)) {
		print_last_error("restoring cursor info");
		successful = false;
	}

	return successful ? 0 : 1;
}

static void print_last_error(const char* context) {
	TCHAR error_buffer[256];
	const DWORD error_size = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS, /* Format msg from the system */
		NULL,
		/* Message format - obtained from error code */
		GetLastError(),
		/* Message ID */
		0,
		/* Language neutral */
		error_buffer,
		/* Output buffer */
		sizeof(error_buffer),
		sizeof(*error_buffer), /* Output buffer size in TCHARs */
		NULL
	/* Arguments for the format string */);
	fprintf(stderr, "An error occurred while %s", context);
	if (0 != error_size) {
		_ftprintf(stderr, _T(": %s"), error_buffer);
	}
	fprintf(stderr, "\n");
}

static bool game_loop(HANDLE screen_handle) {
	// Your code!
}