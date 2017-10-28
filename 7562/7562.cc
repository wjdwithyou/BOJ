#include <iostream>
#include <cstring>

#define DIR 8

typedef struct _Coord {
    int x;
    int y;
}Coord;

const Coord _d[DIR] = { { -1, -2 }, { 1, -2 }, { -2, -1 }, { 2, -1 }, { -2, 1 }, { 2, 1 }, { -1, 2 }, { 1, 2 } };

int board[512][512];
Coord queue[131072];

int bfs(int*, int*, int, Coord, int);
bool operator==(Coord&, Coord&);

int main() {
    Coord knight, goal;
    int T, l, front, back;
    
    scanf("%d", &T);
    
    for (int Ti = 1; Ti <= T; ++Ti) {
        memset(board, 0, sizeof(board));
        front = back = 0;
        
        scanf("%d %d %d %d %d", &l, &knight.x, &knight.y, &goal.x, &goal.y);
        
        queue[back++] = knight;
        ++board[knight.y][knight.x];
        
        printf("%d\n", bfs(&front, &back, l, goal, 0));
    }
    
    return 0;
}

int bfs(int* front, int* back, int size, Coord goal, int depth) {
    if (*front >= *back) {
        return -1;
    }
    
    Coord cur;
    int o_back = *back;
    
    while (*front < o_back) {
        cur = queue[(*front)++];
        
        if (cur == goal) {
            return depth;
        }
        
        for (int i = 0; i < DIR; ++i) {
            if (cur.x + _d[i].x < 0 || cur.y + _d[i].y < 0 || cur.x + _d[i].x >= size || cur.y + _d[i].y >= size) {
                continue;
            }
            
            if (board[cur.y + _d[i].y][cur.x + _d[i].x]) {
                continue;
            }
            
            queue[(*back)++] = { cur.x + _d[i].x, cur.y + _d[i].y };
            ++board[cur.y + _d[i].y][cur.x + _d[i].x];
        }
    }
    
    return bfs(front, back, size, goal, ++depth);
}

bool operator==(Coord &a, Coord &b) {
    return (a.x == b.x && a.y == b.y);
}