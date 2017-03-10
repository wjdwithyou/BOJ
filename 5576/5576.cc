#include <iostream>

int getTop3(int[]);

int main() {
    int w[16], k[16];
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &k[i]);
    }
    
    printf("%d %d", getTop3(w), getTop3(k));
    return 0;
}

int getTop3(int arr[]) {
    int idx, temp;
    int sum = 0;
    
    for (int i = 0; i < 3; ++i) {
        idx = i;
        
        for (int j = i + 1; j < 10; ++j) {
            if (arr[idx] < arr[j]) {
                idx = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
        
        sum += arr[i];
    }
    
    return sum;
}