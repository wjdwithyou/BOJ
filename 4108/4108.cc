#include <iostream>

char board[128][128];

int main() {
    int r, c;
    
    while (true) {
        scanf("%d %d", &r, &c);
        
        if (!r && !c) {
            break;
        }
        
        for (int i = 0; i < r; ++i) {
            scanf("%s", board[i]);
            
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = '0';
                }
            }
        }
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == '*') {
                    for (int a = -1; a <= 1; ++a) {
                        for (int b = -1; b <= 1; ++b) {
                            if (!a && !b || i + a < 0 || i + a >= r || j + b < 0 || j + b >= c || board[i + a][j + b] == '*') {
                                continue;
                            }
                            
                            ++board[i + a][j + b];
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < r; ++i) {
            puts(board[i]);
        }
    }
    
    return 0;
}