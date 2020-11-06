#include <bits/stdc++.h>
#include "terminal.h"

double clamp(double val, double lo, double hi){
    return std::min(std::max(val, lo), hi);
}

double calc(double x, double y, double t, double i){
    bool cond = (1);
    if(!cond){
        return 0.0;
    }
    double val = (double)(sin(atan((y-11.5)/(x-11.5))+t));
    return clamp(val, -1.0, 1.0);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie();
    srand(time(NULL));
    const int rows = 24;
    const int cols = 24;
    double time = 0.0;
    int n;
    std::cout << resizeTerminalByChars(rows, cols*2);
    const double increment = std::max(0.001, (rows*cols)/1000000.0);
    while(true){
        std::cout << moveCursor(0, 0);
        n = 0;
        for(int i = 0; i < rows; i++){
            if(i > 0){
                std::cout << std::endl;
            }
            for(int e = 0; e < cols; e++){
                const int ret = (int)(calc((double)e, (double)i, time, (double)n)*255.0);
                const int r = abs(ret);
                const int gb = std::max(0, ret);
                std::cout << bgColor(r, gb, gb) << "  ";
                n++;
            }
            std::cout << CLEARBG;
        }
        time += increment;
        if(time > 10000000000.0){
            time -= 10000000000.0;
        }
    }
    return 0;
}
