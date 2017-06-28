#include <iostream>

struct Location {
    int x;
    int y;
};

int temp[64][64];
char map[64][64];
Location queue[4096];

int bfs(Location, int*, int*, int);

int main() {
    Location rc;
    int t, front, back;
    int max = 0;
    
    scanf("%d %d", &rc.y, &rc.x);
    
    for (int i = 0; i < rc.y; ++i) {
        scanf("%s", map[i]);
    }
    
    for (int i = 0; i < rc.y; ++i) {
        for (int j = 0; j < rc.x; ++j) {
            if (map[i][j] == 'W') {
                continue;
            }
            
            front = back = 0;
            
            for (int b = 0; b < rc.y; ++b) {
                for (int a = 0; a < rc.x; ++a) {
                    temp[b][a] = 0;
                }
            }
            
            queue[back++] = { j, i };
            ++temp[i][j];
            
            t = bfs(rc, &front, &back, 0);
            
            if (max < t) {
                max = t;
            }
        }
    }
    
    return !printf("%d", max);
}

int bfs(Location rc, int* front, int* back, int d) {
    if (*front == *back) {
        return --d;
    }
    
    Location loc;
    int o_back = *back;
    
    while (*front < o_back) {
        loc = queue[(*front)++];
        
        if (loc.y < rc.y - 1 && map[loc.y + 1][loc.x] == 'L' && !temp[loc.y + 1][loc.x]) {
            queue[(*back)++] = { loc.x, loc.y + 1 };
            ++temp[loc.y + 1][loc.x];
        }
        if (loc.x < rc.x - 1 && map[loc.y][loc.x + 1] == 'L' && !temp[loc.y][loc.x + 1]) {
            queue[(*back)++] = { loc.x + 1, loc.y };
            ++temp[loc.y][loc.x + 1];
        }
        if (loc.y > 0 && map[loc.y - 1][loc.x] == 'L' && !temp[loc.y - 1][loc.x]) {
            queue[(*back)++] = { loc.x, loc.y - 1 };
            ++temp[loc.y - 1][loc.x];
        }
        if (loc.x > 0 && map[loc.y][loc.x - 1] == 'L' && !temp[loc.y][loc.x - 1]) {
            queue[(*back)++] = { loc.x - 1, loc.y };
            ++temp[loc.y][loc.x - 1];
        }
    }
    
    return bfs(rc, front, back, ++d);
}