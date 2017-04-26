#include <iostream>

int main() {
    char buf[512];
    int cnt;
    
    while (true) {
        fgets(buf, 512, stdin);
        
        if (buf[0] == '#') {
            break;
        }
        
        cnt = 0;
        
        for (int i = 0; buf[i] != '\n'; ++i) {
            switch (buf[i]) {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    ++cnt;
                default:
                    break;
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}