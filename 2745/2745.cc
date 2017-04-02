#include <iostream>
#include <cstring>
#include <cmath>

int main() {
    char n[32];
    int b, len;
    int d = 0;
    
    scanf("%s %d", n, &b);
    
    len = strlen(n);
    
    for (int i = len - 1, j = 0; i >= 0; --i) {
        d += ((n[i] < 'A') ? n[i] - '0' : n[i] - 'A' + 10) * static_cast<int>(pow(b, (len - 1) - i));
    }
    
    printf("%d", d);
    return 0;
}