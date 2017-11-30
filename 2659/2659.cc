#include <iostream>

#define MAX 10000
#define N 4

int arr[MAX];

void traversal(int[], int);
int getClockNum(int[]);

int main(void) {
    int n[N], t[N];
    
    setbuf(stdout, NULL);
    
    traversal(t, 0);
    
    for (int i = 0; i < N; ++i) {
        scanf("%d", &n[i]);
    }
    
    for (int i = 1111, k = 0, tn = getClockNum(n); i < MAX; ++i) {
        if (!arr[i]) {
            continue;
        }
        
        ++k;
        
        if (i == tn) {
            printf("%d", k);
            break;
        }
    }
    
    return 0;
}

void traversal(int t[], int d) {
    if (d >= N) {
        arr[getClockNum(t)] = 1;
        return;
    }
    
    for (int i = 1; i <= 9; ++i) {
        t[d] = i;
        traversal(t, d + 1);
    }
    
    return;
}

int getClockNum(int arr[]) {
    int min = MAX;
    
    for (int i = 0, t = 0; i < N; ++i, t = 0) {
        for (int j = i, k = 1000; k; j = (j + 1) % N, k /= 10) {
            t += arr[j] * k;
        }
        
        if (min > t) {
            min = t;
        }
    }
    
    return min;
}