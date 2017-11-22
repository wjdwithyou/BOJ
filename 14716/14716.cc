#include <iostream>

typedef struct _Coord {
    int x;
    int y;
}Coord;

int arr[256][256];
Coord queue[65536];

void bfs(int*, int*, int, int);

int main(void) {
    int m, n;
    int front = 0, back = 0, cnt = 0;
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j]) {
                queue[back++] = { j, i };
                arr[i][j] = 0;
                
                bfs(&front, &back, m, n);
                ++cnt;
            }
        }
    }
    
    return !printf("%d", cnt);
}

void bfs(int* front, int* back, int m, int n) {
    if (*front >= *back) {
        return;
    }
    
    int o_back = *back;
    Coord pos;
    
    while (*front < o_back) {
        pos = queue[(*front)++];
        
        for (int i = 1; i >= -1; --i) {
            for (int j = 1; j >= -1; --j) {
                if (!i && !j) {
                    continue;
                }
                if (pos.x + j < 0 || pos.y + i < 0 || pos.x + j >= n || pos.y + i >= m || !arr[pos.y + i][pos.x + j]) {
                    continue;
                }
                
                queue[(*back)++] = { pos.x + j, pos.y + i };
                arr[pos.y + i][pos.x + j] = 0;
            }
        }
    }
    
    return bfs(front, back, m, n);
}