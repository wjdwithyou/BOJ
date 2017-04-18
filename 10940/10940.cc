#include <iostream>

int main() {
    char buf[64];
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        printf("%c", (buf[i] / 16) + '0');
        
        buf[i] %= 16;
        
        printf("%c", buf[i] + ((buf[i] / 10) ? 'A' - 10 : '0'));
    }
    
    return 0;
}