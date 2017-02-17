#include <iostream>

int arr[1048576];

int main() {
    int n, front, back;
    
    scanf("%d", &n);
    
    for (front = 1, back = 1; back <= n; ++back) {
        arr[back] = back;
    }
    
    while (++front < back) {
        arr[back++] = arr[front++];
    }
    
    printf("%d", arr[--front]);
    return 0;
}