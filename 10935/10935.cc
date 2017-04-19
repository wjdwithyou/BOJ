#include <iostream>

int main() {
    char base64[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int temp[512];
    char buf[64], result[128];
    int t;
    int tidx = 0, ridx = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        for (int j = 0b10000000; j > 0; j >>= 1) {
            temp[tidx++] = buf[i] & j;
        }
    }
    
    while (tidx % 6) {
        temp[tidx++] = 0;
    }
    
    for (int i = 0; i < tidx; i += 6) {
        t = 0;
        
        for (int j = 0b100000, k = 0; k < 6; j >>= 1, ++k) {
            if (temp[i + k]) {
                t += j;
            }
        }
        
        result[ridx++] = base64[t];
    }
    
    while (ridx % 4) {
        result[ridx++] = '=';
    }
    
    result[ridx] = '\0';
    
    return !printf("%s", result);
}