#include <iostream>

int main() {
    char buf[64];
    int h = 10;
    
    scanf("%s", buf);
    
    for (int i = 1; buf[i] != '\0'; ++i) {
        h += (buf[i] == buf[i - 1]) ? 5 : 10;
    }
    
    printf("%d", h);
    return 0;
}