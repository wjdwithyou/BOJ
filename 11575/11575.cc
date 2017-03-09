#include <iostream>

char buf[1048576];

int main() {
    int t, a, b;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &a, &b);
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            buf[j] = ((a * (buf[j] - 'A') + b) % 26) + 'A';
        }
        
        puts(buf);
    }
    
    return 0;
}