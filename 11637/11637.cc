#include <iostream>

int main() {
    int arr[16];
    int t, n, sum, idx, temp, oidx;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        sum = 0;
        
        scanf("%d", &n);
        
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        
        for (int j = 1; j <= 2; ++j) {
            idx = j;
            
            for (int k = j + 1; k <= n; ++k) {
                if (arr[idx] < arr[k]) {
                    idx = k;
                }
            }
            
            temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
            
            if (j == 1) {
                oidx = idx;
            }
        }
        
        if (arr[1] == arr[2]) {
            puts("no winner");
        }
        else {
            printf("%s winner %d\n", (sum - arr[1] < arr[1]) ? "majority" : "minority", oidx);
        }
    }
    
    return 0;
}