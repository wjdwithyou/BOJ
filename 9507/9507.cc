#include <iostream>

#define MAX_NUM 67

int main() {
    unsigned long long int arr[128];
    int t, n;
    
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    for (int i = 4; i <= MAX_NUM; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        printf("%llu\n", arr[n]);
    }
    
    return 0;
}