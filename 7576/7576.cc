#include <iostream>

enum Status { EMPTY = -1, BEFORE, AFTER };

typedef struct Point {
    int x;
    int y;
}Point;

Status arr[1024][1024];
Point queue[1048576];

int bfs(int*, int*, Point, int);

int main() {
    int m, n, day;
    int front = 0, back = 0, ecnt = 0;
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
            
            if (arr[i][j] == AFTER) {
                queue[back++] = { j, i };
            }
            else if (arr[i][j] == EMPTY) {
                ++ecnt;
            }
            else;
        }
    }
    
    day = bfs(&front, &back, {m, n}, -1);
    
    printf("%d", (front == n * m - ecnt) ? day : -1);
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
        
        if (temp.y != max.y - 1 && arr[temp.y + 1][temp.x] == BEFORE) {
            queue[(*back)++] = { temp.x, temp.y + 1 };
            arr[temp.y + 1][temp.x] = AFTER;
        }
        if (temp.x != max.x - 1 && arr[temp.y][temp.x + 1] == BEFORE) {
            queue[(*back)++] = { temp.x + 1, temp.y };
            arr[temp.y][temp.x + 1] = AFTER;
        }
        if (temp.y != 0 && arr[temp.y - 1][temp.x] == BEFORE) {
            queue[(*back)++] = { temp.x, temp.y - 1 };
            arr[temp.y - 1][temp.x] = AFTER;
        }
        if (temp.x != 0 && arr[temp.y][temp.x - 1] == BEFORE) {
            queue[(*back)++] = { temp.x - 1, temp.y };
            arr[temp.y][temp.x - 1] = AFTER;
        }
    }
    
    return bfs(front, back, max, day + 1);
}