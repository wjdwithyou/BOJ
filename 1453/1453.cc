#include <iostream>

int main() {
    int arr[128] = { 0, };
    int n, t;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        (arr[t]) ? ++cnt : ++arr[t];
    }
    
    printf("%d", cnt);
    return 0;
}