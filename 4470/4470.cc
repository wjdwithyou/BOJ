#include <iostream>

int main() {
    char buf[64];
    int n;
    
    scanf("%d", &n);
    while (getchar() != '\n');
    
    for (int i = 1; i <= n; ++i) {
        fgets(buf, 64, stdin);
        printf("%d. %s", i, buf);
    }
    
    return 0;
}