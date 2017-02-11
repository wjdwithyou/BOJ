#include <iostream>

int main() {
    char buf[64];
    int n;
    
    scanf("%d", &n);
    
    while (getchar() != '\n');
    
    for (int i = 0; i < n; ++i) {
        fgets(buf, 64, stdin);
        
        if (buf[0] >= 'a') {
            buf[0] -= 32;
        }
        
        printf("%s", buf);
    }
    
    return 0;
}