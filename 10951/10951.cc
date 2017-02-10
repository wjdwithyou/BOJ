#include <iostream>

int main() {
    int a, b;
    
    while (fscanf(stdin, "%d %d", &a, &b) != EOF) {
        printf("%d\n", a + b);
    }
    
    return 0;
}