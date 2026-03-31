#include "Colors.h"

bool set_color(CHAR_INFO* color, uint8_t color_code) {
	if (color == NULL || color->Attributes == NULL) {
		return false;
	}

	switch (color_code) {
		case EMPTY:
			color->Attributes = BACKGROUND_INTENSITY;
			return true;
		case LIGHT_BLUE:
			color->Attributes = BACKGROUND_INTENSITY | BACKGROUND_BLUE;
			return true;
		case YELLOW:
			color->Attributes = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;
			return true;
		case MAGENTA:
			color->Attributes = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;
			return true;
		case GREEN:
			color->Attributes = BACKGROUND_INTENSITY | BACKGROUND_GREEN;
			return true;
		case RED:
			color->Attributes = BACKGROUND_RED;
			return true;
		case DARK_BLUE:
			color->Attributes = BACKGROUND_BLUE;
			return true;
		case ORANGE:
			color->Attributes = BACKGROUND_RED | BACKGROUND_GREEN;
			return true;
		default:
			return false;
	}
}

bool print_square(uint8_t square, uint32_t column, uint32_t row, HANDLE screen_handle) {
	COORD charBufSize = { 1, 1 };
	COORD characterPos = { 0, 0 };
	SMALL_RECT writeArea = { column, row, column, row };
	CHAR_INFO color = {
		' ',
		BACKGROUND_INTENSITY
	};

	if (!set_color(&color, square)) {
		return false;
	}

	switch (square) {
	case EMPTY:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	case LIGHT_BLUE:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	case YELLOW:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	case MAGENTA:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	case GREEN:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	case RED:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	case DARK_BLUE:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	case ORANGE:
		if (!WriteConsoleOutput(screen_handle, &color, charBufSize, characterPos, &writeArea)) {
			print_last_error("printing grid");
			return false;
		}
		break;
	default:
		return false;
	}
}