#include <iostream>

int arr[2048];

int main() {
    int n, front, back;
    
    scanf("%d", &n);
    
    for (front = 1, back = 0; back <= n; ++back) {
        arr[back] = back;
    }
    
    while (true) {
        printf("%d ", arr[front++]);
        
        if (front == back) {
            break;
        }
        
        arr[back++] = arr[front++];
    }
    
    return 0;
}