#include <stdio.h>
#include <algorithm>

char buffer[256];

//Cursor

const char* cursorUp(int n){
    sprintf(buffer, "\033[%dA", n);
    return buffer;
}

const char* cursorDown(int n){
    sprintf(buffer, "\033[%dB", n);
    return buffer;
}

const char* cursorForward(int n){
    sprintf(buffer, "\033[%dC", n);
    return buffer;
}

const char* cursorBackward(int n){
    sprintf(buffer, "\033[%dD", n);
    return buffer;
}

const char* moveCursor(int line, int column){
    sprintf(buffer, "\033[%d;%dH", line, column);
    return buffer;
}

const char* saveCursorPosition(void){
    sprintf(buffer, "\033[s");
    return buffer;
}

const char* srestoreCursorPosition(void){
    sprintf(buffer, "\033[u");
    return buffer;
}

//Format

const char* textColor(int r, int g, int b){
    r = std::min(r, 255);
    g = std::min(g, 255);
    b = std::min(b, 255);
    r = std::max(r, 0);
    g = std::max(g, 0);
    b = std::max(b, 0);
    sprintf(buffer, "\033[38;2;%d;%d;%dm", r, g, b);
    return buffer;
}

const char* bgColor(int r, int g, int b){
    r = std::min(r, 255);
    g = std::min(g, 255);
    b = std::min(b, 255);
    r = std::max(r, 0);
    g = std::max(g, 0);
    b = std::max(b, 0);
    sprintf(buffer, "\033[48;2;%d;%d;%dm", r, g, b);
    return buffer;
}

const char* bgLineColor(int r, int g, int b){
    r = std::min(r, 255);
    g = std::min(g, 255);
    b = std::min(b, 255);
    r = std::max(r, 0);
    g = std::max(g, 0);
    b = std::max(b, 0);
    sprintf(buffer, "\033[48;2;%d;%d;%dm\033[K", r, g, b);
    return buffer;
}
