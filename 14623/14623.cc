#include <iostream>
#include <cstring>

int main() {
    char b[2][32];
    long long n[2];
    int r[64];
    int idx = 0;
    
    for (int i = 0; i < 2; ++i) {
        n[i] = 0;
        
        scanf("%s", b[i]);
        
        for (int j = strlen(b[i]) - 1, k = 1; j >= 0; --j, k <<= 1) {
            n[i] += (b[i][j] - '0') * k;
        }
    }
    
    n[0] *= n[1];
    
    while (n[0]) {
        r[idx++] = n[0] & 1;
        n[0] >>= 1;
    }
    
    while (idx) {
        printf("%d", r[--idx]);
    }
    
    return 0;
}