#include <iostream>
#include <cmath>

typedef struct Turret {
    int x;
    int y;
    int r;
}Turret;

int main() {
    Turret t1, t2, tt;
    double d;
    int t;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d", &t1.x, &t1.y, &t1.r);
        scanf("%d %d %d", &t2.x, &t2.y, &t2.r);
        
        d = sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
        
        if (t1.r < t2.r) {
            tt = t1;
            t1 = t2;
            t2 = tt;
        }
        
        if (d < t1.r) {
            if (d < t1.r - t2.r) {
                puts("0");
            } else if (d == t1.r - t2.r) {
                puts((!d) ? "-1" : "1");
            } else {
                puts("2");
            }
        } else if (d == t1.r) {
            puts("2");
        } else {
            if (d > t1.r + t2.r) {
                puts("0");
            } else if (d == t1.r + t2.r) {
                puts("1");
            } else {
                puts("2");
            }
        }
    }
    
    return 0;
}