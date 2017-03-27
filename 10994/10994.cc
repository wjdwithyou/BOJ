#include <iostream>

void printStar(int, int);

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= 2 * n - 2; ++i) {
        printStar(n, i);
    }
    
    for (int j = 0; j < 2 * n - 1; ++j) {
        printf("* ");
    }
    puts("");
    
    for (int i = 2 * n - 2; i > 0; --i) {
        printStar(n, i);
    }
    
    return 0;
}

void printStar(int n, int i) {
    for (int j = 0; j < i / 2; ++j) {
        printf("* ");
    }
    
    if (i & 1) {
        for (int j = 0; j < 4 * (n - (i >> 1)) - 3; ++j) {
            printf("*");
        }
    } else {
        for (int j = 0; j < 4 * (n - (i >> 1)) - 3; ++j) {
            printf(" ");
        }
    }
    
    for (int j = 0; j < i / 2; ++j) {
        printf(" *");
    }
    
    puts("");
    return;
}