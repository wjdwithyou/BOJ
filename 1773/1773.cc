#include <iostream>

int arr[2097152];

int main() {
    int n, c, t;
    int cnt = 0;
    
    scanf("%d %d", &n, &c);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        
        for (int j = t; j <= c; j += t) {
            if (!arr[j]++) {
                ++cnt;
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}