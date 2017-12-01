#include <iostream>

#define MAX 32

int main(void) {
    long long arr[MAX];
    long long t = 1;
    int a, b, c;
    
    setbuf(stdout, NULL);
    
    scanf("%d %d %d", &a, &b, &c);
    
    arr[0] = a;
    
    for (int i = 1; i < MAX; ++i) {
        arr[i] = (arr[i - 1] * arr[i - 1]) % c;
    }
    
    for (int i = 0; b; ++i, (b >>= 1)) {
        if (b & 1) {
            t *= arr[i];
            t %= c;
        }
    }
    
    return !printf("%d", static_cast<int>(t));
}