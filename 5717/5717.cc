#include <iostream>

int main() {
    int m, f, c;
    
    do {
        scanf("%d %d", &m, &f);
        c = m + f;
        
        if (c != 0) {
            printf("%d\n", c);
        }
    } while (c != 0);
    return 0;
}