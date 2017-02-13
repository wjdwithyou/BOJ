#include <iostream>
#include <cmath>

int main() {
    char buf[16];
    int n, w1, w2;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        w1 = w2 = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; j < 3; ++j) {
            w1 += (buf[j] - 'A') * static_cast<int>(pow(26, 2 - j));
        }
        
        for (int j = 4; j < 8; ++j) {
            w2 += (buf[j] - '0') * static_cast<int>(pow(10, 7 - j));
        }
        
        w1 -= w2;
        
        
        if (w1 < 0) {
            w1 = -w1;
        }
        
        puts((w1 <= 100) ? "nice" : "not nice");
    }
    
    return 0;
}