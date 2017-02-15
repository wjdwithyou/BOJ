#include <iostream>

int map[64][64];

void checkIsland(int, int, int, int);

int main() {
    int w, h, sum;
    
    while (true) {
        sum = 0;
        
        scanf("%d %d", &w, &h);
        
        if (w == 0 && h == 0) {
            break;
        }
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                scanf("%d", &map[i][j]);
            }
        }
        
        for(int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (map[i][j] == 1) {
                    checkIsland(h, w, i, j);
                    ++sum;
                }
            }
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}

void checkIsland(int h, int w, int i, int j) {
    if (map[i][j] == 0) {
        return;
    }
    
    --map[i][j];
    
    if (i != h - 1 && j != 0) {
        checkIsland(h, w, i + 1, j - 1);
    }
    if (i != h - 1) {
        checkIsland(h, w, i + 1, j);
    }
    if (i != h - 1 && j != w - 1) {
        checkIsland(h, w, i + 1, j + 1);
    }
    if (j != w - 1) {
        checkIsland(h, w, i, j + 1);
    }
    if (i != 0 && j != w - 1) {
        checkIsland(h, w, i - 1, j + 1);
    }
    if (i != 0) {
        checkIsland(h, w, i - 1, j);
    }
    if (i != 0 && j != 0) {
        checkIsland(h, w, i - 1, j - 1);
    }
    if (j != 0) {
        checkIsland(h, w, i, j - 1);
    }
    
    return;
}