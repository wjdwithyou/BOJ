#include <iostream>

#define NUM_COW 10

int main() {
    int cow[16];
    int n, a, b;
    int cnt = 0;
    
    for (int i = 1; i <= NUM_COW; ++i) {
        cow[i] = -1;
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        
        if (cow[a] != -1 && cow[a] != b) {
            ++cnt;
        }
        
        cow[a] = b;
    }
    
    return !printf("%d", cnt);
}