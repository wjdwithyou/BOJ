#include <iostream>
#include <cstring>

int fw[131072];

int main() {
    int t, b, p, q, x, y, s;
    char c;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        memset(fw, 0, sizeof(fw));
        
        scanf("%d %d %d", &b, &p, &q);
        
        for (int j = p + q; j > 0; --j) {
            while (getchar() != '\n');
            scanf("%c %d %d", &c, &x, &y);
            
            if (c == 'P') {
                for (; x <= b; x += (x & -x)) {
                    fw[x] += y;
                }
            } else {
                s = 0;
                
                for (; y; y -= (y & -y)) {
                    s += fw[y];
                }
                for (--x; x; x -= (x & -x)) {
                    s -= fw[x];
                }
                
                printf("%d\n", s);
            }
        }
    }
    
    return 0;
}