#include <iostream>

enum Status { EMPTY = -1, BEFORE, AFTER };

typedef struct Point {
    int x;
    int y;
    int z;
}Point;

Status arr[128][128][128];
Point queue[1048576];

int bfs(int*, int*, Point, int);

int main() {
    int m, n, h, day;
    int front = 0, back = 0, ecnt = 0;
    
    scanf("%d %d %d", &m, &n, &h);
    
    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &arr[k][i][j]);
                
                if (arr[k][i][j] == AFTER) {
                    queue[back++] = { j, i, k };
                }
                else if (arr[k][i][j] == EMPTY) {
                    ++ecnt;
                }
                else;
            }
        }
    }
    
    day = bfs(&front, &back, {m, n, h}, -1);
    
    printf("%d", (front == n * m * h - ecnt) ? day : -1);
    return 0;
}

int bfs(int* front, int* back, Point max, int day) {
    if (*front == *back) {
        return day;
    }
    
    Point temp;
    int o_back = *back;
    
    while (*front < o_back) {
        temp = queue[(*front)++];
        
        if (temp.y != max.y - 1 && arr[temp.z][temp.y + 1][temp.x] == BEFORE) {
            queue[(*back)++] = { temp.x, temp.y + 1, temp.z };
            arr[temp.z][temp.y + 1][temp.x] = AFTER;
        }
        if (temp.x != max.x - 1 && arr[temp.z][temp.y][temp.x + 1] == BEFORE) {
            queue[(*back)++] = { temp.x + 1, temp.y, temp.z };
            arr[temp.z][temp.y][temp.x + 1] = AFTER;
        }
        if (temp.y != 0 && arr[temp.z][temp.y - 1][temp.x] == BEFORE) {
            queue[(*back)++] = { temp.x, temp.y - 1, temp.z };
            arr[temp.z][temp.y - 1][temp.x] = AFTER;
        }
        if (temp.x != 0 && arr[temp.z][temp.y][temp.x - 1] == BEFORE) {
            queue[(*back)++] = { temp.x - 1, temp.y, temp.z };
            arr[temp.z][temp.y][temp.x - 1] = AFTER;
        }
        if (temp.z != max.z - 1 && arr[temp.z + 1][temp.y][temp.x] == BEFORE) {
            queue[(*back)++] = { temp.x, temp.y, temp.z + 1 };
            arr[temp.z + 1][temp.y][temp.x] = AFTER;
        }
        if (temp.z != 0 && arr[temp.z - 1][temp.y][temp.x] == BEFORE) {
            queue[(*back)++] = { temp.x, temp.y, temp.z - 1 };
            arr[temp.z - 1][temp.y][temp.x] = AFTER;
        }
    }
    
    return bfs(front, back, max, day + 1);
}