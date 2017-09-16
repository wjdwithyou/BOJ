#include <iostream>

int main() {
    char buf[8];
    int n, chk;
    
    scanf("%d", &n);
    
    for (int i = n; i >= 4; --i) {
        chk = 0;
        
        sprintf(buf, "%d", i);
        
        for (int j = 0; buf[j]; ++j) {
            if (buf[j] != '4' && buf[j] != '7') {
                ++chk;
                break;
            }
        }
        
        if (!chk) {
            printf("%d", i);
            break;
        }
    }
    
    return 0;
}