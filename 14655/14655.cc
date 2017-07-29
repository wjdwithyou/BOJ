#include <iostream>

int main() {
    int n, t;
    int s = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &t);
            s += abs(t);
        }
    }
    
    return !printf("%d", s);
}