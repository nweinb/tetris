#pragma ONCE
#include <Windows.h>
#include <tchar.h>
#include <stdio.h>

/**
* Convert the last Windows error to string and print
*/
void print_last_error(const char* context);

/**
* Prints given error string
*/
void print_error(const char* context);
