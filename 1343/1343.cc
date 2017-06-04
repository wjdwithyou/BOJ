#include <iostream>
#include <cstring>

int main() {
    char board[512];
    int offset;
    
    scanf("%s", board);
    
    for (int i = 0; board[i] != '\0'; ++i) {
        if (board[i] == '.') {
            continue;
        }
        
        for (offset = 1; offset < 4; ++offset) {
            if (board[i + offset] != 'X') {
                break;
            }
        }
        
        if (offset > 3) {
            for (int j = 0; j < 4; ++j) {
                board[i + j] = 'A';
            }
            i += 3;
        } else if (offset > 1) {
            for (int j = 0; j < 2; ++j) {
                board[i + j] = 'B';
            }
            ++i;
        } else {
            strcpy(&board[0], "-1\0");
            break;
        }
    }
    
    return !printf("%s", board);
}