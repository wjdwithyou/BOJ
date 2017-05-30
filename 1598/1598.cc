#include <iostream>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    --a;
    --b;
    
    return !printf("%d", abs(a / 4 - b / 4) + abs(a % 4 - b % 4));
}