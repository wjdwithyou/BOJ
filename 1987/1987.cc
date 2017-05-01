#include <iostream>
#include <cstring>

enum DIR { DOWN, RIGHT, UP, LEFT };

char board[32][32];

int dfs(int[], int, int, int, int, int, int);

int main() {
    int alpha[32] = { 0, };
    int r, c, t;
    int max = 0;
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; ++i) {
        scanf("%s", board[i]);
    }
    
    ++alpha[board[0][0] - 'A'];
    
    for (int i = DOWN; i <= LEFT; ++i) {
        t = dfs(alpha, r, c, 0, 0, i, 1);
        max = (max < t) ? t : max;
    }
    
    return !printf("%d", max);
}

int dfs(int p_alpha[], int r, int c, int x, int y, int dir, int depth) {
    int alpha[32];
    int t;
    int max = 0;
    
    memcpy(alpha, p_alpha, sizeof(alpha));
    
    if (dir == DOWN && y + 1 < r && !alpha[board[y + 1][x] - 'A']) {
        ++alpha[board[++y][x] - 'A'];
    } else if (dir == RIGHT && x + 1 < c && !alpha[board[y][x + 1] - 'A']) {
        ++alpha[board[y][++x] - 'A'];
    } else if (dir == UP && y > 0 && !alpha[board[y - 1][x] - 'A']) {
        ++alpha[board[--y][x] - 'A'];
    } else if (dir == LEFT && x > 0 && !alpha[board[y][x - 1] - 'A']) {
        ++alpha[board[y][--x] - 'A'];
    } else {
        return depth;
    }
    
    for (int i = DOWN; i <= LEFT; ++i) {
        t = dfs(alpha, r, c, x, y, i, depth + 1);
        max = (max < t) ? t : max;
    }
    
    return max;
}