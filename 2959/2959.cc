#include <iostream>

int main() {
    int arr[4];
    int idx, temp;
    
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 4; ++i) {
        idx = i;
        
        for (int j = i + 1; j < 4; ++j) {
            if (arr[idx] > arr[j]) {
                idx = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    
    printf("%d", arr[0] * arr[2]);
    return 0;
}