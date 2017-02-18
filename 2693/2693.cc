#include <iostream>

#define MAX_NUM 10

int main() {
    const int N = 3;
    int arr[16];
    int t, idx, temp;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < MAX_NUM; ++j) {
            scanf("%d", &arr[j]);
        }
        
        for (int j = 0; j < N; ++j) {
            idx = j;
            
            for (int k = j + 1; k < MAX_NUM; ++k) {
                if (arr[idx] < arr[k]) {
                    idx = k;
                }
            }
            
            temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
        
        printf("%d\n", arr[N - 1]);
    }
    
    return 0;
}