#ifndef TERMINAL_H
#define TERMINAL_H

//Cursor

const char* cursorUp(int n);
const char* cursorDown(int n);
const char* cursorForward(int n);
const char* cursorBackward(int n);
const char* moveCursor(int line, int column);
const char* saveCursorPosition(void);
const char* restoreCursorPosition(void);

//Display

#define CLEARDISPLAY "\033[2J"
#define CLEARLINE "\033[K"
#define CLEARNEWLINE "\n\033[K"

//Format

#define CLEARFORMAT "\033[0m"

#define TEXTBLACK "\033[30m"
#define TEXTRED "\033[31m"
#define TEXTGREEN "\033[32m"
#define TEXTYELLOW "\033[33m"
#define TEXTBLUE "\033[34m"
#define TEXTMAGENTA "\033[35m"
#define TEXTCYAN "\033[36m"
#define TEXTWHITE "\033[37m"
const char* textColor(int r, int g, int b);
#define CLEARTEXT "\033[39m"

#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[46m"
#define BGWHITE "\033[47m"
const char* bgColor(int r, int g, int b);
const char* bgLineColor(int r, int g, int b);
#define CLEARBG "\033[49m"

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define INVERSE "\033[7m"
#define NOBOLD "\033[21m"
#define NOUNDERLINE "\033[24m"
#define NOBLINK "\033[25m"
#define NOINVERSE "\033[27m"

#endif
