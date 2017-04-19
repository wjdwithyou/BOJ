#include <iostream>

int dp[2][512];
int arr[512];

int main() {
    int n;
    
    scanf("%d", &n);
    
    scanf("%d", &arr[1]);
    dp[0][1] = dp[1][1] = arr[1];
    
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &arr[i]);
        
        dp[0][i] = arr[i] + dp[1][i - 1];
        dp[1][i] = arr[i] + ((dp[0][i - 2] > dp[1][i - 2]) ? dp[0][i - 2] : dp[1][i - 2]);
    }
    
    return !printf("%d", (dp[0][n] > dp[1][n]) ? dp[0][n] : dp[1][n]);
}