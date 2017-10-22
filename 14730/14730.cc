#include <iostream>

int main(void) {
    int n, c, o;
    int sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &c, &o);
        sum += c * o;
    }
    
    return !printf("%d", sum);
}