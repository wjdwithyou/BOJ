#include <iostream>

int main() {
    int arr[4] = { 0, 1, 0, 0 };
    int m, x, y, t;
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        
        t = arr[x];
        arr[x] = arr[y];
        arr[y] = t;
    }
    
    for (int i = 1; i <= 3; ++i) {
        if (arr[i]) {
            printf("%d", i);
            break;
        }
    }
    
    return 0;
}