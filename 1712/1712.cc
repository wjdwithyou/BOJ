#include <iostream>

int main() {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    return !printf("%d", (b < c) ? a / (c - b) + 1 : -1);
}