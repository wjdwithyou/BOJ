#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    
    for (int i = 1;; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        
        if (!a && !b && !c) {
            break;
        }
        
        printf("Triangle #%d\n", i);
        
        if (a < 0 && b < c) {
            printf("a = %.3f\n", sqrt(pow(c, 2) - pow(b, 2)));
        } else if (b < 0 && a < c) {
            printf("b = %.3f\n", sqrt(pow(c, 2) - pow(a, 2)));
        } else if (c < 0) {
            printf("c = %.3f\n", sqrt(pow(a, 2) + pow(b, 2)));
        } else {
            puts("Impossible.");
        }
        
        puts("");
    }
    
    return 0;
}