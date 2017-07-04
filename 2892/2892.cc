#include <iostream>

int main() {
    int n, t;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%x", &t);
        printf("%c", (t < 0x20) ? '.' : '-');
    }
    
    return 0;
}