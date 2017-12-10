#include <iostream>

#define ERROR (1e-9)

int arr[131072], tmp[131072];

void divide(int, int);
void merge(int, int, int);

int main(void) {
    double avg;
    int n, k, a, b;
    int sum = 0;
    
    setbuf(stdout, NULL);
    
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d.%d", &a, &b);
        arr[i] = 10 * a + b;
    }
    
    divide(0, n);
    
    for (int i = n - k - 1; i >= k; --i) {
        sum += arr[i];
    }
    
    avg = sum / static_cast<double>(n - (k << 1));
    
    printf("%.2f\n", (avg + ERROR) / 10);
    
    sum = (arr[k] + arr[n - k - 1]) * (k + 1);
    
    for (int i = n - k - 2; i > k; --i) {
        sum += arr[i];
    }
    
    avg = sum / static_cast<double>(n);
    
    return !printf("%.2f", (avg + ERROR) / 10);
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