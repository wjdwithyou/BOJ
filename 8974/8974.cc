#include <iostream>

int arr[1024];

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    for (int i = 1, idx = 1; idx <= b; ++i) {
        for (int j = 0; j < i && idx <= b; ++j, ++idx) {
            arr[idx] = arr[idx - 1] + i;
        }
    }
    
    return !printf("%d", arr[b] - arr[a - 1]);
}