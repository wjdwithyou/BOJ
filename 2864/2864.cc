#include <iostream>

int main() {
    char buf[8];
    int smin = 0, smax = 0;
    
    for (int i = 0; i < 2; ++i) {
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            if (buf[j] == '6') {
                --buf[j];
            }
        }
        
        smin += atoi(buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            if (buf[j] == '5') {
                ++buf[j];
            }
        }
        
        smax += atoi(buf);
    }
    
    printf("%d %d", smin, smax);
    return 0;
}