#include <iostream>
#include <cstring>

int getOctoNum(char);

int main() {
    char buf[16];
    int sum;
    
    while (true) {
        scanf("%s", buf);
        
        if (buf[0] == '#') {
            break;
        }
        
        sum = 0;
        
        for (int i = 1, j = strlen(buf) - 1; j >= 0; i *= 8, --j) {
            sum += i * getOctoNum(buf[j]);
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}

int getOctoNum(char c) {
    switch (c) {
        case '\\':
            return 1;
        case '(':
            return 2;
        case '@':
            return 3;
        case '?':
            return 4;
        case '>':
            return 5;
        case '&':
            return 6;
        case '%':
            return 7;
        case '/':
            return -1;
        case '-':
        default:
            return 0;
    }
}