#include <iostream>

int main() {
    int s, b;
    
    scanf("%d", &s);
    
    for (int i = 0; i < 9; ++i) {
        scanf("%d", &b);
        s -= b;
    }
    
    printf("%d", s);
    return 0;
}