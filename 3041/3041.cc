#include <iostream>

int main() {
    char o_puzzle[4][8] = { "ABCD", "EFGH", "IJKL", "MNO." };
    char puzzle[4][8];
    int sum = 0;
    
    for (int i = 0; i < 4; ++i) {
        scanf("%s", puzzle[i]);
        
        for (int j = 0; j < 4; ++j) {
            if (puzzle[i][j] == '.') {
                continue;
            }
            
            for (int a = 0; a < 4; ++a) {
                for (int b = 0; b < 4; ++b) {
                    if (o_puzzle[a][b] == puzzle[i][j]) {
                        sum += abs(i - a) + abs(j - b);
                        a = b = 4;
                    }
                }
            }
        }
    }
    
    return !printf("%d", sum);
}