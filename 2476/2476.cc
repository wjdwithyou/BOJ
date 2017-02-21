#include <iostream>
#include <cstring>

int main() {
    int arr[8];
    int n, t, idx, prize;
    int max = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        memset(arr, 0, sizeof(arr));
        idx = 1;
        
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &t);
            ++arr[t];
        }
        
        for (int i = 2; i <= 6; ++i) {
            if (arr[idx] <= arr[i]) {
                idx = i;
            }
        }
        
        if (arr[idx] == 3) {
            prize = idx * 1000 + 10000;
        }
        else if (arr[idx] == 2) {
            prize = idx * 100 + 1000;
        }
        else {
            prize = idx * 100;
        }
        
        if (max < prize) {
            max = prize;
        }
    }
    
    printf("%d", max);
    return 0;
}