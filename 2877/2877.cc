#include <iostream>
#include <cmath>

int main(void) {
    char r[32];
    int k, t;
    
    scanf("%d", &k);
    
    for (int i = 2;; ++i) {
        t = static_cast<int>(pow(2, i) - 2);
        
        if (k > t) {
            continue;
        }
        
        r[--i] = '\0';
        
        for (int j = t - k; i >= 0; j >>= 1) {
            r[--i] = ((j & 1) ? 4 : 7) + '0';
        }
        
        break;
    }
    
    return !printf("%s", r);
}