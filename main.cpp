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
    double val = (double)(sin(atan((y-26.5)/(x-56.5))+t));
    return clamp(val, -1.0, 1.0);
}

int main(){
    const int rows = 54;
    const int cols = 113;
    double time = 0.0;
    int n;
    const double increment = std::max(0.001, (rows*cols)/1000000.0);
    while(true){
        printf("%s", moveCursor(1, 0));
        n = 0;
        for(int i = 0; i < rows; i++){
            if(i > 0){
                printf("\n");
            }
            for(int e = 0; e < cols; e++){
                const int ret = (int)(calc((double)e, (double)i, time, (double)n)*255.0);
                const int r = abs(ret);
                const int g = std::max(0, ret);
                const int b = std::max(0, ret);
                printf("%s  ", bgColor(r, g, b));
                n++;
            }
            printf("%s", CLEARBG);
        }
        time += increment;
        if(time > 10000000000.0){
            time -= 10000000000.0;
        }
    }
    return 0;
}
