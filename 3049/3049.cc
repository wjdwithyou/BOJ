#include <iostream>

int main() {
    int n;
    
    scanf("%d", &n);
    n -= 2;
    
    return !printf("%d", static_cast<int>(n * n * (n - 1) * (n - 1) / 24.0f + n * (n - 1) * ((n << 1) - 1) / 12.0f + n * (n - 1) / 6.0f));
}