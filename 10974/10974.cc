#include <iostream>

int dfs(int[], int[], int, int, int);

int main() {
    int arr[16] = { 0 };
    int seq[8];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        dfs(arr, seq, n, i, 0);
    }
    
    return 0;
}

int dfs(int parr[], int seq[], int n, int p, int d) {
    if (d >= n) {
        for (int i = 0; i < d; ++i) {
            printf("%d ", seq[i]);
        }
        
        return printf("\n");
    }
    
    if (parr[p]) {
        return 0;
    }
    
    int arr[16];
    
    for (int i = 1; i <= n; ++i) {
        arr[i] = parr[i];
    }
    
    ++arr[p];
    seq[d] = p;
    
    for (int i = 1; i <= n; ++i) {
        if (dfs(arr, seq, n, i, d + 1)) {
            break;
        }
    }
    
    return 0;
}