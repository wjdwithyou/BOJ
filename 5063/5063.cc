#include <iostream>

int main() {
    int n, r, e, c;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &r, &e, &c);
        
        if (r < e - c) {
            puts("advertise");
        }
        else if (r > e - c) {
            puts("do not advertise");
        }
        else {
            puts("does not matter");
        }
    }
    
    return 0;
}