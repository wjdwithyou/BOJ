#include <iostream>

int arr[1024], tmp[1024];

void divide(int, int);
void merge(int, int, int);

int main(void) {
    int n, l;
    int loc = 0, cnt = 0;
    
    scanf("%d %d", &n, &l);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    divide(0, n);
    
    for (int i = 0; i < n; ++i) {
        if (loc < arr[i]) {
            loc = arr[i] + l - 1;
            ++cnt;
        }
    }
    
    return !printf("%d", cnt);
}

void divide(int a, int b) {
    int m = (a + b) >> 1;
    
    if (a == m) {
        return;
    }
    
    divide(a, m);
    divide(m, b);
    merge(a, m, b);
    
    return;
}

void merge(int a, int m, int b) {
    int idx = a;
    int _a = a;
    int _m = m;
    
    while (_a < m && _m < b) {
        tmp[idx++] = (arr[_a] < arr[_m]) ? arr[_a++] : arr[_m++];
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