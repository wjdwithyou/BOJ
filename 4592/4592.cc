#include <iostream>

int main() {
    int arr[32];
    int n, t, idx;
    
    while (true) {
        idx = 0;
        
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }
        
        scanf("%d", &arr[idx++]);
        
        for (int i = 1; i < n; ++i) {
            scanf("%d", &t);
            
            if (arr[idx - 1] != t) {
                arr[idx++] = t;
            }
        }
        
        for (int i = 0; i < idx; ++i) {
            printf("%d ", arr[i]);
        }
        puts("$");
    }
    
    return 0;
}