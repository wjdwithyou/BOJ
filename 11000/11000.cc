#include <iostream>

typedef struct _Class {
    int s;
    int t;
}Class;

Class arr[262144], tmp[262144];
int tarr[262144];

void divide(int, int);
void merge(int, int, int);

int main(void) {
    int n, s, t;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &arr[i].s, &arr[i].t);
    }
    
    divide(0, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0;; ++j) {
            if (tarr[j] > arr[i].s) {
                continue;
            }
            
            tarr[j] = arr[i].t;
            
            if (cnt < j) {
                cnt = j;
            }
            
            break;
        }
    }
    
    return !printf("%d", ++cnt);
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
        if (arr[_a].s == arr[_m].s) {
            tmp[idx++] = (arr[_a].t < arr[_m].t) ? arr[_a++] : arr[_m++];
        } else {
            tmp[idx++] = (arr[_a].s < arr[_m].s) ? arr[_a++] : arr[_m++];
        }
    }
    while (_a < m) {
        tmp[idx++] = arr[_a++];
    }
    while (_m < b) {
        tmp[idx++] = arr[_m++];
    }
    
    for (int i = a; i < b; ++i) {
        arr[i] = tmp[i];
    }
    
    return;
}