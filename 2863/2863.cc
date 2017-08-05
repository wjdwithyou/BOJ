#include <iostream>

int main() {
    int a, b, c, d, t, cnt;
    int min = 16384;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    for (int i = 0; i < 4; ++i) {
        t = c * d;
        
        if (min > t) {
            min = t;
            cnt = i;
        }
        
        t = a;
        a = c;
        c = d;
        d = b;
        b = t;
    }
    
    return !printf("%d", cnt);
}