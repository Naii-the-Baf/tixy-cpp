#include <bits/stdc++.h>
#include "terminal.h"

double clamp(double val, double lo, double hi){
    return std::min(std::max(val, lo), hi);
}

double calc(double x, double y, double t, double i){
    double u=x-8.5;
    double v=y-8.5;
    bool cond = (1);
    if(!cond){
        return 0.0;
    }
    double val = (double)(1-fmod((u*u+v*v)/t, 3));
    return clamp(val, -1.0, 1.0);
}

void midcolor(const int rgbbase[3], const int rgb1[3], const int rgb2[3], int rgbret[3], double val){
    if(val < 128.0){
        for(int i = 0; i < 3; i++){
            rgbret[i] = (int)((double)(rgb1[i]-rgbbase[i])/127.0*val)+rgbbase[i];
        }
    } else {
        val -= 128.0;
        for(int i = 0; i < 3; i++){
            rgbret[i] = (int)((double)(rgb2[i]-rgb1[i])/127.0*val)+rgb1[i];
        }
    }
    return;
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
    const double increment = std::max(0.001, (rows*cols)/500000.0);
    const int rgbbase[3] = {0, 0, 0};
    while(true){
        std::cout << moveCursor(0, 0);
        n = 0;
        for(int i = 0; i < rows; i++){
            if(i > 0){
                std::cout << std::endl;
            }
            for(int e = 0; e < cols; e++){
                const double ret = round(calc((double)e, (double)i, time, (double)n)*255.0);
                int rgb[3] = {0, 0, 0};
                if(ret<0.0){
                    const int rgb1[3] = {255, 255, 0};
                    const int rgb2[3] = {255, 0, 0};
                    midcolor(rgbbase, rgb1, rgb2, rgb, -ret);
                } else {
                    const int rgb1[3] = {0, 0, 255};
                    const int rgb2[3] = {0, 255, 255};
                    midcolor(rgbbase, rgb1, rgb2, rgb, ret);
                }
                std::cout << bgColor(rgb[0], rgb[1], rgb[2]) << "  ";
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
