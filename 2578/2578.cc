#include <iostream>

#define MAX 5

struct Loc {
    int x;
    int y;
};

Loc line[16][8] = {
    { { 0, 4 }, { 1, 3 }, { 2, 2 }, { 3, 1 }, { 4, 0 } },
    { { 0, 4 }, { 1, 4 }, { 2, 4 }, { 3, 4 }, { 4, 4 } },
    { { 0, 3 }, { 1, 3 }, { 2, 3 }, { 3, 3 }, { 4, 3 } },
    { { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 }, { 4, 2 } },
    { { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 }, { 4, 1 } },
    { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 }, { 4, 0 } },
    { { 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 } },
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } },
    { { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 } },
    { { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 } },
    { { 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 3 }, { 3, 4 } },
    { { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 } }
};

int countLine(int[][8]);

int main() {
    int bingo[8][8];
    int t, ichk;
    int ochk = 0;
    
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            scanf("%d", &bingo[i][j]);
        }
    }
    
    for (int k = 1; k <= MAX * MAX; ++k) {
        scanf("%d", &t);
        
        if (ochk) {
            continue;
        }
        
        ichk = 0;
        
        for (int i = 0; i < MAX && !ichk; ++i) {
            for (int j = 0; j < MAX && !ichk; ++j) {
                if (bingo[i][j] == t) {
                    bingo[i][j] = 0;
                    ++ichk;
                }
            }
        }
        
        if (countLine(bingo) >= 3) {
            printf("%d", k);
            ++ochk;
        }
    }
    
    return 0;
}

int countLine(int bingo[][8]) {
    int sum;
    int cnt = 0;
    
    for (int a = MAX * 2 + 1; a >= 0; --a) {
        sum = 0;
        
        for (int b = 0; b < MAX; ++b) {
            sum += bingo[line[a][b].y][line[a][b].x];
        }
        
        if (!sum) {
            ++cnt;
        }
    }
    
    return cnt;
}