#include <iostream>

int main() {
    char buf[4];
    int a, b;
    
    scanf("%d %d", &a, &b);
    sprintf(buf, "%d", b);
    
    for (int i = 2; i >= 0; --i) {
        printf("%d\n", a * (buf[i] - '0'));
    }
    
    printf("%d\n", a * b);
    return 0;
}