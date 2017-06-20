#include <iostream>
#include <cstring>

char arr[128][32];

int main() {
    char buf[256];
    int n, m, len, idx;
    
    while (1) {
        scanf("%d", &m);
        
        if (!m) {
            break;
        }
        
        idx = 0;
        
        scanf("%s", buf);
        len = strlen(buf);
        n = len / m;
        
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                for (int j = m - 1; j >= 0; --j) {
                    arr[i][j] = buf[idx++];
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    arr[i][j] = buf[idx++];
                }
            }
        }
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                printf("%c", arr[i][j]);
            }
        }
        puts("");
    }
    
    return 0;
}