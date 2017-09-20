#include <iostream>

int sum[1024][1024];
char arr[1024][1024];

int main() {
    int n, m, size, tmp;
    int max = 0;
    
    scanf("%d %d", &n, &m);
    
    size = (n < m) ? n : m;
    
    for (int i = 1; i <= n; ++i) {
        scanf("%s", &arr[i][1]);
        
        for (int j = 1; j <= m; ++j) {
            sum[i][j] = (arr[i][j] - '0') + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
    }
    
    for (int k = 1; k <= size; ++k) {
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= m; ++j) {
                tmp = sum[i][j] - sum[i][j - k] - sum[i - k][j] + sum[i - k][j - k];
                
                if (tmp == k * k && max < tmp) {
                    max = tmp;
                }
            }
        }
    }
    
    return !printf("%d", max);
}