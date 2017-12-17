#include <iostream>

int arr[131072], tmp[131072];

void divide(int, int);
void merge(int, int, int);

int main(void) {
    setbuf(stdout, NULL);
    
    int n;
    int max = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    divide(1, n + 1);
    
    for (int i = 1; i <= n; ++i) {
        if (max < arr[i] * i) {
            max = arr[i] * i;
        }
    }
    
    return !printf("%d", max);
}

void divide(int a, int b) {
    int m = (a + b) >> 1;
    
    if (a == m) {
        return;
    }
    
    divide(a, m);
    divide(m, b);
    
    return merge(a, m, b);
}

void merge(int a, int m, int b) {
    int idx = a;
    int _a = a;
    int _m = m;
    
    while (_a < m && _m < b) {
        tmp[idx++] = (arr[_a] > arr[_m]) ? arr[_a++] : arr[_m++];
    }
    while (_a < m) {
        tmp[idx++] = arr[_a++];
    }
    while (_m < b) {
        tmp[idx++] = arr[_m++];
    }
    
    for (idx = a; idx < b; ++idx) {
        arr[idx] = tmp[idx];
    }
    
    return;
}