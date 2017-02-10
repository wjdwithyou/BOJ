#include <iostream>

int main() {
    char buf[128];
    int cnt = 1;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] == ',') {
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}