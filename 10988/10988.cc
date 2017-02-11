#include <iostream>
#include <cstring>

int main() {
    char buf[128];
    int i, j;
    int chk = 1;
    
    scanf("%s", buf);
    
    for (i = 0, j = strlen(buf) - 1; i < j; ++i, --j) {
        if (buf[i] != buf[j]) {
            --chk;
            break;
        }
    }
    
    printf("%d", chk);
    return 0;
}