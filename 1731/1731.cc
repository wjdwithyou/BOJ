#include <iostream>

int main() {
    int a[64];
    double r;
    int n, d;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    if (a[2] - a[1] == a[1] - a[0]) {
        d = a[1] - a[0];
        printf("%d", a[n - 1] + d);
    } else {
        r = a[1] / static_cast<double>(a[0]);
        printf("%.10g", a[n - 1] * r);
    }
    
    return 0;
}