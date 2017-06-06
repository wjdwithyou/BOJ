#include <iostream>
#include <cmath>

#define MIN 2992

int main() {
    int d[4] = { 10, 12, 16 };
    int s[4];
    int n, t;
    
    for (int i = MIN; i < 10000; ++i) {
        for (int k = 0; k < 3; ++k) {
            s[k] = 0;
            n = i;
            
            for (int j = 3; j >= 0; --j) {
                t = static_cast<int>(pow(d[k], j));
                s[k] += n / t;
                n %= t;
            }
        }
        
        if (s[0] == s[1] && s[1] == s[2] && s[2] == s[0]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}