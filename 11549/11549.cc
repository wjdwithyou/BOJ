#include <iostream>

int main() {
    int t, x;
    int c = 0;
    
    scanf("%d", &t);
    
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &x);
        
        if (x == t) {
            ++c;
        }
    }
    
    return !printf("%d", c);
}