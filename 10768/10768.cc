#include <iostream>

int main() {
    int m, d;
    
    scanf("%d %d", &m, &d);
    
    if (m < 2 || m == 2 && d < 18) {
        printf("Before");
    } else if (m > 2 || m == 2 && d > 18) {
        printf("After");
    } else {
        printf("Special");
    }
    
    return 0;
}