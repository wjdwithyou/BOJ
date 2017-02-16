#include <iostream>
#include <cmath>

int main() {
    int r, w, l;
    
    for (int i = 1;; ++i) {
        scanf("%d", &r);
        
        if (r == 0) {
            break;
        }
        
        scanf("%d", &w);
        scanf("%d", &l);
        
        if (pow(static_cast<double>(w) / 2, 2) + pow(static_cast<double>(l) / 2, 2) <= pow(r, 2)) {
            printf("Pizza %d fits on the table.\n", i);
        }
        else {
            printf("Pizza %d does not fit on the table.\n", i);
        }
    }
    
    return 0;
}