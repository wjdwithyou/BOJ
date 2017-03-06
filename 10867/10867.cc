#include <iostream>

#define MAX_NUM 1000

int arr[2048];

int main() {
    int n, t;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ++arr[t + MAX_NUM];
    }
    
    for (int i = 0; i <= 2 * MAX_NUM; ++i) {
        if (arr[i]) {
            printf("%d ", i - MAX_NUM);
        }
    }
    
    return 0;
}