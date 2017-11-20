#include <iostream>

int main(void) {
    int s, t, d;
    
    scanf("%d %d %d", &s, &t, &d);
    
    return !printf("%d", t * d / (s << 1));
}