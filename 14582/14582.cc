#include <iostream>

int main() {
    int score[2][16];
    int t;
    int chk = 0;
    
    for (int i = 0; i < 2; ++i) {
        score[i][0] = 0;
        
        for (int j = 1; j <= 9; ++j) {
            scanf("%d", &t);
            score[i][j] = score[i][j - 1] + t;
        }
    }
    
    for (int j = 1; j <= 9; ++j) {
        if (score[0][j] > score[1][j - 1]) {
            ++chk;
            break;
        }
    }
    
    return !printf((chk)? "Yes" : "No");
}