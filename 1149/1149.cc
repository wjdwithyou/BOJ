#include <iostream>
#include <climits>

int arr[3][1024];

int main() {
    int rgb[3];
    int n, tmin, tsum;
    
    scanf("%d", &n);
    
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < 3; ++i) {
            tmin = INT_MAX;
            
            scanf("%d", &rgb[i]);
            
            if (j == 0) {
                arr[i][j] = rgb[i];
                continue;
            }
            
            for (int k = 0; k < 3; ++k) {
                if (i == k) {
                    continue;
                }
                
                tsum = rgb[i] + arr[k][j - 1];
                
                if (tmin > tsum) {
                    tmin = tsum;
                }
            }
            
            arr[i][j] = tmin;
        }
    }
    
    tmin = INT_MAX;
    
    for (int i = 0; i < 3; ++i) {
        if (tmin > arr[i][n - 1]) {
            tmin = arr[i][n - 1];
        }
    }
    
    printf("%d", tmin);
    return 0;
}