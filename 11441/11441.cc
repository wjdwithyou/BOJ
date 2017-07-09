#include <iostream>

int arr[131072];

int main() {
    int n, m, t, a, b;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        arr[i] = arr[i - 1] + t;
    }
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[b] - arr[--a]);
    }
    
    return 0;
}