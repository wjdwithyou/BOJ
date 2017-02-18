#include <iostream>

int main() {
    int t;
    int m = 0, s = 0;
    
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &t);
        s += t;
    }
    
    m += (s / 60);
    s -= (m * 60);
    
    printf("%d\n%d", m, s);
    return 0;
}