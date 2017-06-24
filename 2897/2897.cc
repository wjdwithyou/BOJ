#include <iostream>

char map[64][64];

int main() {
    int cnt[8] = { 0 };
    int r, c, t, chk;
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; ++i) {
        scanf("%s", map[i]);
    }
    
    for (int i = 0; i < r - 1; ++i) {
        for (int j = 0; j < c - 1; ++j) {
            t = chk = 0;
            
            for (int a = 0; a < 2 && !chk; ++a) {
                for (int b = 0; b < 2 && !chk; ++b) {
                    if (map[i + a][j + b] == '#') {
                        ++chk;
                    } else if (map[i + a][j + b] == 'X') {
                        ++t;
                    }
                }
            }
            
            if (!chk) {
                ++cnt[t];
            }
        }
    }
    
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", cnt[i]);
    }
    
    return 0;
}