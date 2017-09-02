#include <iostream>
#include <cstring>
#include <cmath>

#define SUM 14

int main() {
    char hoh[4];
    int n;
    double lf, t;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s = %lf", hoh, &lf);
        
        t = -log10(lf);
        
        printf("%.2f\n", (strlen(hoh) < 2) ? t : SUM - t);
    }
    
    return 0;
}