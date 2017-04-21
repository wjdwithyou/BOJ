#include <iostream>

int dp[4][16384];

int getMax(int);

int main() {
    int n, t;
    
    scanf("%d", &n);
    
    dp[1][0] = dp[2][0] = dp[3][0] = 0;
    
    for (int i = 1; i < 3; ++i) {
        scanf("%d", &t);
        dp[1][i] = dp[2][i] = dp[3][i] = t;
    }
    
    dp[1][2] += dp[2][1];
    
    for (int i = 3; i <= n; ++i) {
        scanf("%d", &t);
        
        dp[1][i] = t + ((dp[2][i - 1] > dp[3][i - 1]) ? dp[2][i - 1] : dp[3][i - 1]);
        dp[2][i] = t + getMax(i - 2);
        dp[3][i] = t + getMax(i - 3);
    }
    
    return !printf("%d", (getMax(n) < getMax(n - 1)) ? getMax(n - 1) : getMax(n));
}

int getMax(int idx) {
    int max = 0;
    
    for (int i = 1; i <= 3; ++i) {
        if (max < dp[i][idx]) {
            max = dp[i][idx];
        }
    }
    
    return max;
}