#include <iostream>

#define MAX_NUM 3

int main() {
    int arr[4];
    char buf[4];
    int idx, temp;
    
    for (int i = 0; i < MAX_NUM; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < MAX_NUM; ++i) {
        idx = i;
        
        for (int j = i + 1; j < MAX_NUM; ++j) {
            if (arr[idx] > arr[j]) {
                idx = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        printf("%d ", arr[buf[i] - 'A']);
    }
    
    return 0;
}