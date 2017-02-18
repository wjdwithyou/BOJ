#include <iostream>

int main() {
    int n, a, b, sa, sb;
    
    sa = sb = 100;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        
        if (a < b) {
            sa -= b;
        }
        else if (a > b) {
            sb -= a;
        }
        else;
    }
    
    printf("%d\n%d", sa, sb);
    return 0;
}