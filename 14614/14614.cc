#include <iostream>
#include <cstring>

int main() {
    char c[128];
    int a, b;
    
    scanf("%d %d %s", &a, &b, c);
    
    return !printf("%d", (c[strlen(c) - 1] & 1) ? a ^ b : a);
}