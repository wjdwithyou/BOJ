#include <iostream>

int main() {
    int e, f, c, t;
    int cnt = 0;
    
    scanf("%d %d %d", &e, &f, &c);
    
    do {
        t = e + f;
        e = t % c;
        f = t / c;
        cnt += f;
    } while (f);
    
    return !printf("%d", cnt);
}