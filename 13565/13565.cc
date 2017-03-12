#include <iostream>

enum Status { CONDUCT = 48, INSULATE };

typedef struct Point {
    int x;
    int y;
}Point;

char arr[1024][1024];
Point queue[1048576];

bool bfs(int*, int*, int, int);

int main() {
    int m, n;
    int front = 0, back = 0;
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; ++i) {
        scanf("%s", arr[i]);
    }
    
    for (int j = 0; j < n; ++j) {
        if (arr[0][j] == CONDUCT) {
            queue[back++] = { j, 0 };
            arr[0][j] = INSULATE;
        }
    }
    
    puts(bfs(&front, &back, m, n) ? "YES" : "NO");
    return 0;
}

bool bfs(int* front, int* back, int m, int n) {
    if (*front == *back) {
        return false;
    }
    
    int o_back = *back;
    
    while (*front < o_back) {
        Point temp = queue[(*front)++];
        
        if (temp.y == m - 1) {
            return true;
        }
        
        if (arr[temp.y + 1][temp.x] == CONDUCT) {
            queue[(*back)++] = { temp.x, temp.y + 1 };
            arr[temp.y + 1][temp.x] = INSULATE;
        }
        if (temp.x != n - 1 && arr[temp.y][temp.x + 1] == CONDUCT) {
            queue[(*back)++] = { temp.x + 1, temp.y };
            arr[temp.y][temp.x + 1] = INSULATE;
        }
        if (temp.y != 0 && arr[temp.y - 1][temp.x] == CONDUCT) {
        queue[(*back)++] = { temp.x, temp.y - 1 };
            arr[temp.y - 1][temp.x] = INSULATE;
        }
        if (temp.x != 0 && arr[temp.y][temp.x - 1] == CONDUCT) {
            queue[(*back)++] = { temp.x - 1, temp.y };
            arr[temp.y][temp.x - 1] = INSULATE;
        }
    }
    
    return bfs(front, back, m, n);
}