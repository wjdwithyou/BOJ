#include <iostream>

int main() {
    int a[16];
    int t;
    int wa = 0, wb = 0;
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &t);
        
        if (a[i] > t) {
            ++wa;
        } else if (a[i] < t) {
            ++wb;
        } else;
    }
    
    if (wa > wb) {
        printf("A");
    } else if (wa < wb) {
        printf("B");
    } else {
        printf("D");
    }
    
    return 0;
}