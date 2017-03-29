#include <iostream>

int main() {
    int t, x, y, z;
    char op;
    
    scanf("%d", &t);
    
    for (int i = 1; i <= t; ++i) {
        scanf("%d %c %d = %d", &x, &op, &y, &z);
        printf("Case %d: %s\n", i, (z == ((op == '+') ? x + y : x - y)) ? "YES" : "NO");
    }
    
    return 0;
}