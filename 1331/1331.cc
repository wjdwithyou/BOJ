#include <iostream>
#include <cstring>

int boardCheck(int[][8], char[]);
int moveCheck(char[], char[]);

int main() {
    int board[8][8] = { 0, };
    char buf[4], first[4], prev[4];
    int valid = 1;
    
    scanf("%s", buf);
    
    if (boardCheck(board, buf)) {
        --valid;
    } else {
        strcpy(first, buf);
        strcpy(prev, buf);
    }
    
    for (int i = 1; i < 36; ++i) {
        scanf("%s", buf);
        
        if (!valid) {
            continue;
        }
        
        if (boardCheck(board, buf) || moveCheck(buf, prev)) {
            --valid;
        }
    }
    
    if (valid && moveCheck(first, prev)) {
        --valid;
    }
    
    printf((valid) ? "Valid" : "Invalid");
    return 0;
}

int boardCheck(int board[][8], char buf[]) {
    int a = buf[0] - 'A' + 1;
    int b = buf[1] - '0';
    
    if (a >= 1 && a <= 6 && b >= 1 && b <= 6 && !board[b][a]) {
        ++board[b][a];
        return 0;
    }
    
    return -1;
}

int moveCheck(char buf[], char prev[]) {
    int a = abs(buf[0] - prev[0]);
    int b = abs(buf[1] - prev[1]);
    
    if (a == 1 && b == 2 || a == 2 && b == 1) {
        strcpy(prev, buf);
        return 0;
    }
    
    return -1;
}