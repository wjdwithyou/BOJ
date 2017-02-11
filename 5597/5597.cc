#include <iostream>

int main() {
    int arr[32] = { 0, };
    int n;
    
    for (int i = 0; i < 28; ++i) {
        scanf("%d", &n);
        ++arr[n];
    }
    
    for (int i = 1; i <= 30; ++i) {
        if (!arr[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}