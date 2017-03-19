#include <iostream>

int arr[1024];

int main() {
    int n, m, a, b;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        ++arr[a], ++arr[b];
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}