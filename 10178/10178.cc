#include <iostream>

int main() {
    int t, a, b;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &a, &b);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", a / b, a % b);
    }
    
    return 0;
}