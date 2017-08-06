#include <iostream>

int arr[1024];

int getGCD(int, int);

int main() {
    int c, n, a, b;
    
    arr[1] = 3;
    
    for (int i = 2; i <= 1000; ++i) {
        a = i;
        b = 1;
        
        arr[i] += arr[i - 1];
        
        for (; b < i; ++b) {
            if (getGCD(a, b) < 2) {
                ++arr[i];
            }
        }
        for (; a > 0; --a) {
            if (getGCD(a, b) < 2) {
                ++arr[i];
            }
        }
    }
    
    scanf("%d", &c);
    
    for (int i = 0; i < c; ++i) {
        scanf("%d", &n);
        printf("%d\n", arr[n]);
    }
    
    return 0;
}

int getGCD(int a, int b) {
    int t;
    
    if (a > b) {
        t = b;
        b = a;
        a = t;
    }
    
    do {
        t = b % a;
        b = a;
        a = t;
    } while (a);
    
    return b;
}