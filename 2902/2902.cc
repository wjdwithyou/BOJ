#include <iostream>

int main() {
    char buf[128];
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] >= 'A' && buf[i] <= 'Z') {
            printf("%c", buf[i]);
        }
    }
    
    return 0;
}