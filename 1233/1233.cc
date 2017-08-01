#include <iostream>

int main() {
    int cnt[128] = { 0 };
    int a, b, c, idx;
    
    scanf("%d %d %d", &a, &b, &c);
    
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                ++cnt[i + j + k];
            }
        }
    }
    
    idx = 3;
    
    for (int i = 4; i < 80; ++i) {
        if (cnt[idx] < cnt[i]) {
            idx = i;
        }
    }
    
    return !printf("%d", idx);
}