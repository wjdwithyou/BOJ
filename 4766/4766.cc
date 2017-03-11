#include <iostream>

int main() {
    float p, t;
    
    scanf("%f", &p);
    
    while (true) {
        scanf("%f", &t);
        
        if (t == 999) {
            break;
        }
        
        printf("%.2f\n", t - p);
        
        p = t;
    }
    
    return 0;
}