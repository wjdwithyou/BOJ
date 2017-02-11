#include <iostream>

int main() {
    int a[8] = {1, 1, 2, 2, 2, 8};
    int b[8];
    
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &b[i]);
        a[i] -= b[i];
        printf("%d ", a[i]);
    }
    
    return 0;
}