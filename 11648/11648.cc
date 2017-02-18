#include <iostream>

int main() {
    char buf[16];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0;; ++i) {
        if (n < 10) {
            printf("%d", i);
            break;
        }
        
        sprintf(buf, "%d", n);
        
        n = 1;
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            n *= (buf[j] - '0');
        }
    }
    
    return 0;
}