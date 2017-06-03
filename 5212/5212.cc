#include <iostream>

typedef struct Location {
    int x;
    int y;
}Location;

int main() {
    char map[16][16];
    Location diff[128];
    int r, c, cnt;
    Location min = { 16, 16 };
    Location max = { -1, -1 };
    int idx = 0;
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; ++i) {
        scanf("%s", map[i]);
    }
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (map[i][j] == '.') {
                continue;
            }
            
            cnt = 0;
            
            if (i < r - 1 && map[i + 1][j] == 'X') {
                ++cnt;
            }
            if (j < c - 1 && map[i][j + 1] == 'X') {
                ++cnt;
            }
            if (i > 0 && map[i - 1][j] == 'X') {
                ++cnt;
            }
            if (j > 0 && map[i][j - 1] == 'X') {
                ++cnt;
            }
            
            if (cnt < 2) {
                diff[idx++] = { j, i };
                continue;
            }
            
            if (j < min.x) {
                min.x = j;
            }
            if (j > max.x) {
                max.x = j;
            }
            if (i < min.y) {
                min.y = i;
            }
            if (i > max.y) {
                max.y = i;
            }
        }
    }
    
    for (int i = 0; i < idx; ++i) {
        map[diff[i].y][diff[i].x] = '.';
    }
    
    for (int i = min.y; i <= max.y; ++i) {
        for (int j = min.x; j <= max.x; ++j) {
            printf("%c", map[i][j]);
        }
        puts("");
    }
    
    return 0;
}