#include <iostream>

int main() {
    char buf[16];
    int cnt = 0;
    
    for (int i = 0; i < 8; ++i) {
        scanf("%s", buf);
        
        for (int j = 0; j < 8; ++j) {
            if ((i & 1) == (j & 1) && buf[j] == 'F') {
                ++cnt;
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}