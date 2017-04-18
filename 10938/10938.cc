#include <iostream>
#include <cstring>

int main() {
    char base32[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
    int temp[512];
    char buf[64], result[128];
    int t;
    int tidx = 0, ridx = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        for (int j = 0b10000000; j > 0; j >>= 1) {
            temp[tidx++] = buf[i] / j;
            buf[i] %= j;
        }
    }
    
    while (tidx % 5) {
        temp[tidx++] = 0;
    }
    
    for (int i = 0; i < tidx; i += 5) {
        t = 0;
        
        for (int j = 0b10000, k = 0; k < 5; j >>= 1, ++k) {
            if (temp[i + k]) {
                t += j;
            }
        }
        
        result[ridx++] = base32[t];
    }
    
    while (ridx % 8) {
        result[ridx++] = '=';
    }
    
    result[ridx] = '\0';
    
    return !printf("%s", result);
}