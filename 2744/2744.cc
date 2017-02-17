#include <iostream>

int main() {
    char buf[128];
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        buf[i] += (buf[i] >= 'a') ? -32 : 32;
    }
    
    printf("%s", buf);
    return 0;
}