#include <iostream>
#include <cstring>

int getGCD(int, int);

int main() {
    int arr[128];
    int t, n, sum;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        memset(arr, 0, sizeof(arr));
        sum = 0;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
        }
        
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                sum += getGCD(arr[j], arr[k]);
            }
        }
        
        printf("%d\n", sum);
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
    } while(a);
    
    return b;
}