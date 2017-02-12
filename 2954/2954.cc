#include <iostream>

int main() {
    char buf[128];
    int chk;
    
    fgets(buf, 128, stdin);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        switch (buf[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                i += 2;
            default:
                break;
        }
        
        printf("%c", buf[i]);
    }
    
    return 0;
}