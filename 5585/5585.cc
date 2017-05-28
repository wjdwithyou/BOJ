#include <iostream>

int main() {
    int money[8] = { 500, 100, 50, 10, 5, 1 };
    int cnt = 0;
    int n;
    
    scanf("%d", &n);
    
    n = 1000 - n;
    
    for (int i = 0; n; ++i) {
        cnt += n / money[i];
        n %= money[i];
    }
    
    return !printf("%d", cnt);
}