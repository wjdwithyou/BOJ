#include <iostream>

int main() {
    int x, y, w, h;
    
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    x = (x < w - x)? x : w - x;
    y = (y < h - y)? y : h - y;
    
    printf("%d", (x < y)? x : y);
    return 0;
}