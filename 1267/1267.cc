#include <iostream>

int main() {
    int n, t;
    int y = 0, m = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        
        y += (10 * (t / 30 + 1));
        m += (15 * (t / 60 + 1));
    }
    
    if (y == m) {
        printf("Y M %d", y);
    } else if (y < m) {
        printf("Y %d", y);
    } else {
        printf("M %d", m);
    }
    
    return 0;
}