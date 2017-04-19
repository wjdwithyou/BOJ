#include <iostream>

int main() {
    int temp[512];
    char buf[128], result[64];
    int t;
    int tidx = 0, ridx = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '=' && buf[i] != '\0'; ++i) {
        if (buf[i] == '+') {
            buf[i] = 62;
        } else if (buf[i] == '/') {
            buf[i] = 63;
        } else if (buf[i] >= 'A' && buf[i] <= 'Z') {
            buf[i] -= 'A';
        } else if (buf[i] >= 'a' && buf[i] <= 'z') {
            buf[i] -= 'a' - 26;
        } else {
            buf[i] += 4;
        }
        
        for (int j = 0b100000; j > 0; j >>= 1) {
            temp[tidx++] = buf[i] & j;
        }
    }
    
    while (tidx % 8) {
        --tidx;
    }
    
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