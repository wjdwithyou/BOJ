#include <iostream>
#include <cstring>

int main() {
    char buf[128];
    int len;
    
    scanf("%s", buf);
    
    len = strlen(buf);
    
    switch (len % 3) {
        case 2:
            printf("%d", (buf[0] - '0') * 2 + (buf[1] - '0'));
            break;
        case 1:
            printf("%d", buf[0] - '0');
            break;
        case 0:
        default:
            break;
    }
    
    for (int i = len % 3; i < len; i += 3) {
        printf("%d", (buf[i] - '0') * 4 + (buf[i + 1] - '0') * 2 + (buf[i + 2] - '0'));
    }
    
    return 0;
}