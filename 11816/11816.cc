#include <iostream>
#include <cstring>

int main() {
    char buf[16];
    int len;
    int r = 0;
    
    scanf("%s", buf);
    len = strlen(buf);
    
    if (buf[1] == 'x') {
        for (int i = 2; i < len; ++i) {
            r <<= 4;
            r |= (buf[i] <= '9') ? (buf[i] - '0') : (buf[i] - 'a' + 10);
        }
    } else if (buf[0] == '0') {
        for (int i = 1; i < len; ++i) {
            r <<= 3;
            r |= (buf[i] - '0');
        }
    } else {
        r = atoi(buf);
    }
    
    printf("%d", r);
    return 0;
}