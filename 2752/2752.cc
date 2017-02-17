#include <iostream>

int main() {
    int arr[4];
    int idx, temp;
    
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 3; ++i) {
        idx = i;
        
        for (int j = i + 1; j < 3; ++j) {
            if (arr[idx] > arr[j]) {
                idx = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    
    for (int i = 0; i < 3; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}