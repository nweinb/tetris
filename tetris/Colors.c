#include "Colors.h"

CHAR_INFO* black() {
    CHAR_INFO black;
    black.Char.AsciiChar = ' ';

    black.Attributes = 0;

    return &black;
}

CHAR_INFO* gray() {
    CHAR_INFO gray;
    gray.Char.AsciiChar = ' ';

    gray.Attributes = BACKGROUND_INTENSITY;

    return &gray;
}

CHAR_INFO* light_blue() {
    CHAR_INFO lightBlue;
    lightBlue.Char.AsciiChar = ' ';

    lightBlue.Attributes = BACKGROUND_INTENSITY | BACKGROUND_BLUE;
   
    return &lightBlue;
}

CHAR_INFO* yellow() {
    CHAR_INFO yellow;
    yellow.Char.AsciiChar = ' ';

    yellow.Attributes = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;

    return &yellow;
}

CHAR_INFO* magenta() {
    CHAR_INFO magenta;
    magenta.Char.AsciiChar = ' ';

    magenta.Attributes = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;

    return &magenta;
}

CHAR_INFO* green() {
    CHAR_INFO green;
    green.Char.AsciiChar = ' ';

    green.Attributes = BACKGROUND_INTENSITY | BACKGROUND_GREEN;

    return &red;
}

CHAR_INFO* red() {
    CHAR_INFO red;
    red.Char.AsciiChar = ' ';

    red.Attributes = BACKGROUND_RED;

    return &red;
}

CHAR_INFO* dark_blue() {
    CHAR_INFO darkBlue;
    darkBlue.Char.AsciiChar = ' ';

    darkBlue.Attributes = BACKGROUND_BLUE;

    return &darkBlue;
}

CHAR_INFO* orange() {
    CHAR_INFO orange;
    orange.Char.AsciiChar = ' ';

    orange.Attributes = BACKGROUND_RED | BACKGROUND_GREEN;

    return &orange;
}