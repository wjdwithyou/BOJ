#include <iostream>

int main() {
    int mmax[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d, m, y, s;
    
    while (true) {
        mmax[2] = 28;
        s = 0;
        
        scanf("%d %d %d", &d, &m, &y);
        
        if (d == 0 || m == 0 || y == 0) {
            break;
        }
        
        mmax[2] += (y % 4 == 0) ? ((y % 100 == 0) ? ((y % 400 == 0)? 1 : 0) : 1) : 0;
        
        for (int i = 1; i < m; ++i) {
            s += mmax[i];
        }
        
        s += d;
        
        printf("%d\n", s);
    }
    
    return 0;
}