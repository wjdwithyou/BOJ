#include <iostream>

int main() {
    int pmn[4];
    int a, b, c, d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &pmn[i]);
    }
    
    b += a;
    d += c;
    
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", (pmn[i] % b > 0 && pmn[i] % b <= a) + (pmn[i] % d > 0 && pmn[i] % d <= c));
    }
    
    return 0;
}