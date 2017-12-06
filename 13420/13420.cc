#include <iostream>

long long getResult(long long, long long, char);

int main(void) {
    long long a, b, r;
    int T;
    char c;
    
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    
    for (int Ti = 0; Ti < T; ++Ti) {
        scanf("%lld %c %lld = %lld", &a, &c, &b, &r);
        puts((getResult(a, b, c) == r) ? "correct" : "wrong answer");
    }
    
    return 0;
}

long long getResult(long long a, long long b, char c) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}