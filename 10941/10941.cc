#include <iostream>

int main() {
    char buf[128];
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; i += 2) {
        printf("%c", (buf[i] - '0') * 16 + buf[i + 1] - ((buf[i + 1] <= '9') ? '0' : 'A' - 10));
    }
    
    return 0;
}