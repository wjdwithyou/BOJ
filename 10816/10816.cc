#include <iostream>

#define MAX 10000000

int arr[2 * MAX + 1];

int main() {
    int n, m, t;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ++arr[t + MAX];
    }
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d", &t);
        printf("%d ", arr[t + MAX]);
    }
    
    return 0;
}