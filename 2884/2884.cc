#include <iostream>

int main() {
    int h, m;
    
    scanf("%d %d", &h, &m);
    
    m -= 45;
    
    if (m < 0) {
        h += (--h < 0) ? 24 : 0;
        m += 60;
    }
    
    printf("%d %d", h, m);
    return 0;
}