#include <iostream>

typedef struct Point {
    int x;
    int y;
}Point;

typedef struct Status {
    Point r;
    Point b;
}Status;

Status queue[16384];
int chk[10][10][10][10];

int bfs(int*, int*, char[][16], Point, int);
void move(char[][16], Status, int, Point, Point*, Point*, int*, int*);
char setOrder(Status*, int, Point**, Point**);
bool operator==(Point, Point);

int main() {
    char board[16][16];
    Point r, b, o;
    int n, m;
    int front = 0, back = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
        
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                r = {j, i};
            } else if (board[i][j] == 'B') {
                b = {j, i};
            } else if (board[i][j] == 'O') {
                o = {j, i};
            } else;
        }
    }
    
    queue[back++] = {r, b};
    ++chk[r.y][r.x][b.y][b.x];
    
    printf("%d", bfs(&front, &back, board, o, 1));
    return 0;
}

int bfs(int* front, int* back, char board[][16], Point o, int cnt) {
    if (*front >= *back || cnt > 10) {
        return 0;
    }
    
    int ro, bo;
    Point nr, nb;
    Status status;
    int o_back = *back;
    
    while (*front < o_back) {
        status = queue[(*front)++];
        
        for (int i = 0; i < 4; ++i) {
            move(board, status, i, o, &nr, &nb, &ro, &bo);
            
            if (bo) {
                continue;
            }
            
            if (ro) {
                return 1;
            }
            
            if (!chk[nr.y][nr.x][nb.y][nb.x]) {
                queue[(*back)++] = {nr, nb};
                ++chk[nr.y][nr.x][nb.y][nb.x];
            }
        }
    }
    
    return bfs(front, back, board, o, cnt + 1);
}

void move(char board[][16], Status status, int dir, Point o, Point* nr, Point* nb, int* ro, int* bo) {
    Point tf, ts;
    Point *first, *second;
    int fo = 0, so = 0;
    char fc = setOrder(&status, dir, &first, &second);
    
    switch (dir) {
        case 0:
            for (tf = {(*first).x, (*first).y + 1};; ++tf.y) {
                if (board[tf.y][tf.x] == '#') {
                    --tf.y;
                    break;
                } else if (o == tf) {
                    tf = { 0, 0 };
                    ++fo;
                    break;
                } else;
            }
            for (ts = {(*second).x, (*second).y + 1};; ++ts.y) {
                if (board[ts.y][ts.x] == '#' || tf == ts) {
                    --ts.y;
                    break;
                } else if (o == ts) {
                    ++so;
                    break;
                } else;
            }
            break;
        case 1:
            for (tf = {(*first).x + 1, (*first).y};; ++tf.x) {
                if (board[tf.y][tf.x] == '#') {
                    --tf.x;
                    break;
                } else if (o == tf) {
                    tf = { 0, 0 };
                    ++fo;
                    break;
                } else;
            }
            for (ts = {(*second).x + 1, (*second).y};; ++ts.x) {
                if (board[ts.y][ts.x] == '#' || tf == ts) {
                    --ts.x;
                    break;
                } else if (o == ts) {
                    ++so;
                    break;
                } else;
            }
            break;
        case 2:
            for (tf = {(*first).x, (*first).y - 1};; --tf.y) {
                if (board[tf.y][tf.x] == '#') {
                    ++tf.y;
                    break;
                } else if (o == tf) {
                    tf = { 0, 0 };
                    ++fo;
                    break;
                } else;
            }
            for (ts = {(*second).x, (*second).y - 1};; --ts.y) {
                if (board[ts.y][ts.x] == '#' || tf == ts) {
                    ++ts.y;
                    break;
                } else if (o == ts) {
                    ++so;
                    break;
                } else;
            }
            break;
        case 3:
            for (tf = {(*first).x - 1, (*first).y};; --tf.x) {
                if (board[tf.y][tf.x] == '#') {
                    ++tf.x;
                    break;
                } else if (o == tf) {
                    tf = { 0, 0 };
                    ++fo;
                    break;
                } else;
            }
            for (ts = {(*second).x - 1, (*second).y};; --ts.x) {
                if (board[ts.y][ts.x] == '#' || tf == ts) {
                    ++ts.x;
                    break;
                } else if (o == ts) {
                    ++so;
                    break;
                } else;
            }
            break;
        default:
            break;
    }
    
    *nr = (fc == 'B') ? ts : tf;
    *nb = (fc == 'B') ? tf : ts;
    
    *ro = (fc == 'B') ? so : fo;
    *bo = (fc == 'B') ? fo : so;
    
    return;
}

char setOrder(Status* status, int dir, Point** first, Point** second) {
    int chk = 0;
    
    if (dir == 0 && (*status).r.y < (*status).b.y) {
        ++chk;
    } else if (dir == 1 && (*status).r.x < (*status).b.x) {
        ++chk;
    } else if (dir == 2 && (*status).r.y > (*status).b.y) {
        ++chk;
    } else if (dir == 3 && (*status).r.x > (*status).b.x) {
        ++chk;
    } else;
    
    *first = (chk) ? &(*status).b : &(*status).r;
    *second = (chk) ? &(*status).r : &(*status).b;
    
    return (chk) ? 'B': 'R';
}

bool operator==(Point a, Point b) {
    return (a.x == b.x && a.y == b.y);
}