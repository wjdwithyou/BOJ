#include <iostream>
#include <cmath>

int divide(int, int, int, int);

int main(void) {
    int n, r, c;
    
    setbuf(stdout, NULL);
    
    scanf("%d %d %d", &n, &r, &c);
    
    return !printf("%d", divide(static_cast<int>(pow(2, n)) >> 1, r, c, 0));
}

int divide(int n, int r, int c, int out) {
    if (!n) {
        return out;
    }
    
    if (r >= n) {
        out += 2 * static_cast<int>(pow(n, 2));
        r -= n;
    }
    if (c >= n) {
        out += static_cast<int>(pow(n, 2));
        c -= n;
    }
    
    return divide(n >> 1, r, c, out);
}