#include <iostream>

int arr[131072], brr[131072];

void divide(int, int);
void merge(int, int, int);
int binarySearch(int, int, int);

int main() {
    int n, m, t;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    divide(0, n);
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d", &t);
        printf("%d\n", binarySearch(0, n, t));
    }
    
    return 0;
}

void divide(int a, int b) {
    if (a == b) {
        return;
    }
    
    int m = (a + b) >> 1;
    
    if (m != a) {
        divide(a, m);
        divide(m, b);
    }
    
    merge(a, m, b);
    
    return;
}

void merge(int a, int m, int b) {
    int _a = a;
    int _m = m;
    
    for (int i = a; i < b; ++i) {
        if (_a >= m) {
            brr[i] = arr[_m++];
        }
        else if (_m >= b) {
            brr[i] = arr[_a++];
        }
        else {
            brr[i] = (arr[_a] < arr[_m]) ? arr[_a++] : arr[_m++];
        }
    }
    
    for (int i = a; i < b; ++i) {
        arr[i] = brr[i];
    }
    
    return;
}

int binarySearch(int a, int b, int t) {
    int m = (a + b) >> 1;
    
    if (m == a) {
        return (t == arr[a] || t == arr[b]) ? 1 : 0;
    }
    
    if (arr[m] == t) {
        return 1;
    }
    else if (arr[m] > t) {
        return binarySearch(a, m, t);
    }
    else {
        return binarySearch(m, b, t);
    }
}