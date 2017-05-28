#include <iostream>

int main() {
    int a, b;
    char c;
    
    scanf("%d", &a);
    
    while (1) {
        while (getchar() != '\n');
        scanf("%c", &c);
        
        if (c == '=') {
            break;
        }
        
        scanf("%d", &b);
        
        if (c == '+') {
            a += b;
        } else if (c == '-') {
            a -= b;
        } else if (c == '*') {
            a *= b;
        } else if (c == '/') {
            a /= b;
        }
    }
    
    return !printf("%d", a);
}