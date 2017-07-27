#include <iostream>

struct Poly {
    long long coef;
    long long cons;
};

Poly makePoly(long long, long long);
Poly operator-(const Poly&, const Poly&);
Poly operator*(const Poly&, const int&);

int main() {
    Poly a, b, r;
    long long x, y;
    int z;
    
    while (fscanf(stdin, "%lld %lld", &x, &y) != EOF) {
        z = static_cast<int>(100 * y / x) + 1;
        
        if (z >= 100) {
            puts("-1");
            continue;
        }
        
        a = makePoly(1, y) * 100;
        b = makePoly(1, x) * z;
        
        r = (a.coef > b.coef)\
            ? makePoly(a.coef - b.coef, b.cons - a.cons)\
            : makePoly(b.coef - a.coef, a.cons - b.cons);
        
        printf("%lld\n", r.cons / r.coef + (r.cons % r.coef != 0));
    }
    
    return 0;
}

Poly makePoly(long long coef, long long cons) {
    Poly t = { coef, cons };
    return t;
}

Poly operator-(const Poly &a, const Poly &b) {
    Poly t = { a.coef - b.coef, a.cons - b.cons };
    return t;
}

Poly operator*(const Poly &a, const int &b) {
    Poly t = { b * a.coef, b * a.cons };
    return t;
}