#include <iostream>

int main() {
    int x;
    
    scanf("%d", &x);
    
    return !printf("%d", 111 * x * x + 11 * x + 1);
}