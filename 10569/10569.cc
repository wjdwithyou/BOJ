#include <iostream>

int main() {
    int t, v, e;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &v, &e);
        printf("%d\n", e - v + 2);
    }
    
    return 0;
}