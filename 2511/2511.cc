#include <iostream>

int main() {
    int arr[16];
    int t;
    int a = 0, b = 0;
    char last = 'D';
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &t);
        
        if (arr[i] > t) {
            a += 3;
            last = 'A';
        } else if (arr[i] < t) {
            b += 3;
            last = 'B';
        } else {
            ++a, ++b;
        }
    }
    
    printf("%d %d\n%c", a, b, (a == b) ? last : ((a > b) ? 'A' : 'B'));
    return 0;
}