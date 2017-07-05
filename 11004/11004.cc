#include <iostream>

#define MAX 5000000

char buf[67108864];
int arr[MAX], brr[MAX];

void divide(int, int);
void merge(int, int, int);

int main() {
    int t, chk;
    int n = 0, k = 0, idx = 0;
    
    fread(buf, 1, 67108864, stdin);
    
    for (; buf[idx] != ' '; ++idx) {
        n *= 10;
        n += buf[idx] - '0';
    }
    for (++idx; buf[idx] != '\n'; ++idx) {
        k *= 10;
        k += buf[idx] - '0';
    }
    
    for (int i = 0; i < n; ++i) {
        for (t = 0, chk = 0, ++idx; buf[idx] != ' ' && buf[idx] != '\n' && buf[idx] != EOF; ++idx) {
            if (!t && buf[idx] == '-') {
                ++chk;
                continue;
            }
            
            t *= 10;
            t += buf[idx] - '0';
        }
        
        if (chk) {
            t = -t;
        }
        
        arr[i] = t;
    }
    
    divide(0, n);
    
    return !printf("%d", arr[--k]);
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
        brr[idx++] = (arr[_a] < arr[_m]) ? arr[_a++] : arr[_m++];
    }
    while (_a < m) {
        brr[idx++] = arr[_a++];
    }
    while (_m < b) {
        brr[idx++] = arr[_m++];
    }
    
    for (int i = a; i < b; ++i) {
        arr[i] = brr[i];
    }
    
    return;
}