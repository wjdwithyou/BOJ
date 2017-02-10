#include <iostream>
#include <cmath>

char buf[8192];

int main() {
    int t, b, k;
    char r = 0;
    
    scanf("%d", &t);
    
    for (int i = 1; i <= t; ++i) {
        scanf("%d", &b);
        scanf("%s", buf);
        
        printf("Case #%d: ", i);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            k = j % 8;
            
            if (buf[j] == 'I') {
                r += static_cast<char>(pow(2, 7 - k));
            }
            
            if (k == 7) {
                printf("%c", r);
                r = 0;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}