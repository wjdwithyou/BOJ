#include <iostream>

int main() {
    const int a = 300, b = 60, c = 10;
    int t, temp;
    
    scanf("%d", &t);
    
    if (t % 10) {
        printf("-1");
    } else {
        temp = t;
        printf("%d ", temp / a);
        
        temp %= a;
        printf("%d ", temp / b);
        
        temp %= b;
        printf("%d ", temp / c);
    }
    
    return 0;
}