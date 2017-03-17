#include <iostream>

int arr[131072];

int main() {
    int n, idx, sum;
    
    while (true) {
        idx = sum = 0;
        
        scanf("%d", &n);
        
        if (n == -1) {
            break;
        }
        
        for (int i = 1; sum <= n && i <= (n >> 1); ++i) {
            if (n % i) {
                continue;
            }
            
            arr[idx++] = i;
            sum += i;
        }
        
        if (sum == n) {
            printf("%d = 1", n);
            for (int i = 1; i < idx; ++i) {
                printf(" + %d", arr[i]);
            }
            printf("\n");
        } else {
            printf("%d is NOT perfect.\n", n);
        }
    }
    
    return 0;
}