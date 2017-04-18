#include <iostream>

int main() {
    int temp[512];
    char buf[128], result[64];
    int t;
    int tidx = 0, ridx = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '=' && buf[i] != '\0'; ++i) {
        buf[i] -= (buf[i] < 'A') ? '0' - 26 + 2 : 'A';
        
        for (int j = 0b10000; j > 0; j >>= 1) {
            temp[tidx++] = buf[i] / j;
            buf[i] %= j;
        }
    }
    
    tidx -= tidx % 8;
    
    for (int i = 0; i < tidx; i += 8) {
        t = 0;
        
        for (int j = 0b10000000, k = 0; k < 8; j >>= 1, ++k) {
            if (temp[i + k]) {
                t += j;
            }
        }
        
        result[ridx++] = t;
    }
    
    result[ridx] = '\0';
    
    return !printf("%s", result);
}