#include <iostream>
#include <cmath>

int main() {
    int di, hr, wr;
    double x;
    
    scanf("%d %d %d", &di, &hr, &wr);
    
    x = sqrt(pow(di, 2) / (pow(hr, 2) + pow(wr, 2)));
    
    printf("%.0f %.0f", floor(x * hr), floor(x * wr));
    return 0;
}