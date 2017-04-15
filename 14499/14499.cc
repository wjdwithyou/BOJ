#include <iostream>

typedef struct Dice {
    int plane[8];
    int x;
    int y;
    int status;
}Dice;

typedef struct Node {
    int top;
    int bottom;
    int next[4];
}Node;

Node dfa[24] = {
    { 1, 6, { 4, 1, 3, 12 }},
    { 4, 3, { 5, 2, 0, 13 }},
    { 6, 1, { 6, 3, 1, 14 }},
    { 3, 4, { 7, 0, 2, 15 }},
    { 5, 2, { 8, 16, 18, 0 }},
    { 5, 2, { 9, 17, 19, 1 }},
    { 5, 2, { 10, 22, 20, 2 }},
    { 5, 2, { 11, 23, 21, 3 }},
    { 6, 1, { 12, 11, 9, 4 }},
    { 3, 4, { 13, 8, 10, 5 }},
    { 1, 6, { 14, 9, 11, 6 }},
    { 4, 3, { 15, 10, 8, 7 }},
    { 2, 5, { 0, 20, 22, 8 }},
    { 2, 5, { 1, 21, 23, 9 }},
    { 2, 5, { 2, 18, 16, 10 }},
    { 2, 5, { 3, 19, 17, 11 }},
    { 4, 3, { 17, 14, 4, 23 }},
    { 6, 1, { 22, 15, 5, 16 }},
    { 3, 4, { 21, 4, 14, 19 }},
    { 1, 6, { 18, 5, 15, 20 }},
    { 4, 3, { 19, 6, 12, 21 }},
    { 6, 1, { 20, 7, 13, 18 }},
    { 3, 4, { 23, 12, 6, 17 }},
    { 1, 6, { 16, 13, 7, 22 }}
};

int map[32][32];

int main() {
    Dice dice;
    int n, m, k, d, chk;
    
    scanf("%d %d %d %d %d", &n, &m, &dice.y, &dice.x, &k);
    
    for (int i = 1; i <= 6; ++i) {
        dice.plane[i] = 0;
    }
    dice.status = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    
    for (int i = 0; i < k; ++i) {
        chk = 0;
        
        scanf("%d", &d);
        d %= 4;
        
        switch (d) {
            case 0:
                if (dice.y + 1 < n) {
                    ++chk;
                    ++dice.y;
                }
                break;
            case 1:
                if (dice.x + 1 < m) {
                    ++chk;
                    ++dice.x;
                }
                break;
            case 2:
                if (dice.x > 0) {
                    ++chk;
                    --dice.x;
                }
                break;
            case 3:
                if (dice.y > 0) {
                    ++chk;
                    --dice.y;
                }
                break;
            default:
                break;
        }
        
        if (!chk) {
            continue;
        }
        
        dice.status = dfa[dice.status].next[d];
        
        if (map[dice.y][dice.x]) {
            dice.plane[dfa[dice.status].bottom] = map[dice.y][dice.x];
            map[dice.y][dice.x] = 0;
        } else {
            map[dice.y][dice.x] = dice.plane[dfa[dice.status].bottom];
        }
        
        printf("%d\n", dice.plane[dfa[dice.status].top]);
    }
    
    return 0;
}