#include <iostream>

int main() {
    char buf[128];
    int len = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        ++len;
    }
    
    printf("%d", len);
    return 0;
}