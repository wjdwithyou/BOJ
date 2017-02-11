#include <iostream>

int main() {
    int n, t;
    int s = 0, chk = 0;
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &n);
        
        if (chk) {
            continue;
        }
        
        t = s + n;
        
        if (t <= 100) {
            s = t;
            
            if (s == 100) {
                ++chk;
            }
        }
        else {
            if (100 - s >= t - 100) {
                s = t;
            }
            
            ++chk;
        }
    }
    
    printf("%d", s);
    return 0;
}