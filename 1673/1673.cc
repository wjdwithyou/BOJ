#include <iostream>

int main() {
    int n, k, s, t;
    
    while (fscanf(stdin, "%d %d", &n, &k) != EOF) {
        s = n;
        
        while (n >= k) {
            t = n / k;
            s += t;
            n = t + (n % k);
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}