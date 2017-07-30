#include <iostream>

int main() {
    int n;
    
    scanf("%d", &n);
    
    return !printf("%s", (n & 1) ? "CY" : "SK");
}