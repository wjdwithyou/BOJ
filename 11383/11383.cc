#include <iostream>

int main() {
    char img[16][16];
    char buf[16];
    int n, m;
    int chk = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", img[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        
        for (int j = 0; j < m && !chk; ++j) {
            if (img[i][j] != buf[j << 1] || img[i][j] != buf[(j << 1) + 1]) {
                ++chk;
            }
        }
    }
    
    return !printf("%sEyfa", (chk) ? "Not " : "");
}