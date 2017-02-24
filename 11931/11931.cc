#include <iostream>

int arr[1048576], brr[1048576];

void divide(int, int);
void merge(int, int, int);

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    divide(0, n);
    
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}

void divide(int a, int b) {
    int m = ((a + b) >> 1);
    
    if (a == m) {
        return;
    }
    
    divide(a, m);
    divide(m, b);
    merge(a, m, b);
    
    return;
}

void merge(int a, int m, int b) {
    int o_a = a, o_m = m;
    
    for (int i = o_a; i < b; ++i) {
        if (o_m <= a) {
            brr[i] = arr[m++];
        } else if(b <= m) {
            brr[i] = arr[a++];
        } else {
            brr[i] = (arr[a] > arr[m]) ? arr[a++]: arr[m++];
        }
    }
    
    for (int i = o_a; i < b; ++i) {
        arr[i] = brr[i];
    }
    
    return;
}