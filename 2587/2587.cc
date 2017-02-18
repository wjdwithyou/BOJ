#include <iostream>

#define MAX_NUM 5

int main() {
    int arr[8];
    int idx, t;
    int sum = 0;
    
    for (int i = 0; i < MAX_NUM; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    for (int i = 0; i < MAX_NUM; ++i) {
        idx = i;
        
        for (int j = i + 1; j < MAX_NUM; ++j) {
            if (arr[idx] > arr[j]) {
                idx = j;
            }
        }
        
        t = arr[i];
        arr[i] = arr[idx];
        arr[idx] = t;
    }
    
    printf("%d\n%d", sum / MAX_NUM, arr[MAX_NUM >> 1]);
    return 0;
}