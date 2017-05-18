#include <iostream>
#include <cstring>

int main() {
    char buf[8];
    int len;
    int width;
    
    while (1) {
        scanf("%s", buf);
        
        if (buf[0] == '0') {
            break;
        }
        
        len = strlen(buf);
        width = len + 1;
        
        for (int i = 0; i < len; ++i) {
            width += (buf[i] > '1') ? 3 : ((buf[i] == '0') ? 4 : 2);
        }
        
        printf("%d\n", width);
    }
    
    return 0;
}