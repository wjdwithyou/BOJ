#include <iostream>
#include <cmath>

int main() {
    double n;
    
    scanf("%lf", &n);
    
    n = ceil(sqrt(n));
    
    printf("%.0f", n);
    return 0;
}