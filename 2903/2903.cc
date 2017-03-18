#include <iostream>
#include <cmath>

int main() {
    int n;
    
    scanf("%d", &n);
    printf("%d", static_cast<int>(pow(pow(2, n) + 1, 2)));
    
    return 0;
}