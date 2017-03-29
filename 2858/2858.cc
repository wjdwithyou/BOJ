#include <iostream>
#include <cmath>

int main() {
    double r, b, x, y;
    
    scanf("%lf %lf", &r, &b);
    
    x = r / 4 + 1;
    y = sqrt(r * r / 16 - r / 2 - b + 1);
    
    printf("%.0f %.0f", x + y, x - y);
    return 0;
}