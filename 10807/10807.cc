#include <iostream>

int main() {
    int counter[256] = { 0, };
    int n, t;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ++counter[t + 100];
    }
    
    scanf("%d", &t);
    printf("%d", counter[t + 100]);
    
    return 0;
}