#include <iostream>

#define MAX_NUM 42

int main() {
    int arr[64] = { 0, };
    int t;
    int sum = 0;
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &t);
        arr[t % MAX_NUM] = 1;
    }
    
    for (int i = 0; i < MAX_NUM; ++i) {
        sum += arr[i];
    }
    
    printf("%d", sum);
    return 0;
}