#include <iostream>

int getNext(int[], int*, int);

int main() {
    int arr[16] = { 0, };
    int n;
    int d = 1;
    
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0");
        return 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (getNext(arr, &d, 0) == -1) {
            printf("-1");
            return 0;
        }
    }
    
    for (int i = d - 1; i >= 0; --i) {
        printf("%d", arr[i]);
    }
    
    return 0;
}

int getNext(int arr[], int* d, int c) {
    ++arr[c];
    
    if (c == *d - 1) {
        if (arr[c] > 9) {
            arr[c] = c;
            arr[*d] = *d;
            
            if (++(*d) > 10) {
                return -1;
            }
        }
    }
    else {
        if (arr[c] == arr[c + 1]) {
            arr[c] = c;
            return getNext(arr, d, c + 1);
        }
    }
    
    return 0;
}