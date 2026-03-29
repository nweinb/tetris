#pragma ONCE
#include <Windows.h>
#include <stdbool.h>
#include <conio.h>
#include <stdio.h>
#include <stdint.h>

#include "Board.h"
#include "Errors.h"
#include "Movement.h"

#define SLEEP_TIME_MS 300
#define QUIT 'q'
#define LEFT 'a'
#define RIGHT 'd'

/*
* Starts game loop
* Params: screen_handle - screen to play on
*/
bool game_loop(HANDLE screen_handle);

