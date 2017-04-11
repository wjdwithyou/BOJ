#include <iostream>
#include <cstring>

char table[256][32];

int main() {
    char buf[256];
    int k, r;
    int idx = 0;
    
    scanf("%d", &k);
    scanf("%s", buf);
    
    r = strlen(buf) / k;
    
    for (int i = 0; i < r; ++i) {
        if (i & 1) {
            for (int j = k - 1; j >= 0; --j) {
                table[i][j] = buf[idx++];
            }
        } else {
            for (int j = 0; j < k; ++j) {
                table[i][j] = buf[idx++];
            }
        }
    }
    
    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < r; ++i) {
            printf("%c", table[i][j]);
        }
    }
    
    return 0;
}