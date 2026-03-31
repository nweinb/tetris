#pragma once
#include <Windows.h>
#include <stdint.h>
#include <stdbool.h>

#include "Errors.h"
#include "EnumCodes.h"

/*
* Sets the color of the given char attribute
* Params: color - char attribute to change color of
*		  color_code - color to change char to
*/
bool set_color(CHAR_INFO* color, uint8_t color_code);

/*
* Prints square to output stream
* Params: square - square value to print
*		  column - column to print square
*		  row - row to print square
*		  screen_handle - screen to print to
*/
bool print_square(uint8_t square, uint32_t column, uint32_t row, HANDLE screen_handle);
