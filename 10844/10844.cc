#include <iostream>

#define DIV 1000000000

int dp[16][128];

int main() {
    int n;
    int cnt = 0;
    
    for (int i = 1; i <= 9; ++i) {
        dp[i][1] = 1;
    }
    
    scanf("%d", &n);
    
    for (int j = 2; j <= n; ++j) {
        dp[0][j] = dp[1][j - 1];
        
        for (int i = 1; i < 9; ++i) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1]) % DIV;
        }
        
        dp[9][j] = dp[8][j - 1];
    }
    
    for (int i = 0; i <= 9; ++i) {
        cnt += dp[i][n];
        cnt %= DIV;
    }
    
    return !printf("%d", cnt);
}