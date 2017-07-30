#include <iostream>

int main() {
    char result[256], buf[64];
    int r, c, zr, zc;
    
    scanf("%d %d %d %d", &r, &c, &zr, &zc);
    
    result[c * zc] = '\0';
    
    for (int i = 0; i < r; ++i) {
        scanf("%s", buf);
        
        for (int j = 0; j < c; ++j) {
            for (int b = 0; b < zc; ++b) {
                result[j * zc + b] = buf[j];
            }
        }
        
        for (int a = 0; a < zr; ++a) {
            puts(result);
        }
    }
    
    return 0;
}