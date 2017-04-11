#include <iostream>
#include <cmath>

int main() {
    char buf[8] = { 0, };
    int t, d;
    
    scanf("%d", &t);
    
    for (int i = 0; i < 5; ++i) {
        d = static_cast<int>(pow(9, 4 - i));
        
        buf[i] = t / d + '0';
        t %= d;
    }
    
    printf("%d", atoi(buf));
    return 0;
}