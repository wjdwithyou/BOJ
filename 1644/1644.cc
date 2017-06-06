#include <iostream>

int arr[4194304], pn[2097152];

int main() {
    int n;
    int t = 0, cnt = 0;
    int pidx = 0, front = 0, back = -1;
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i) {
        if (arr[i]) {
            continue;
        }
        
        pn[pidx++] = i;
        
        for (int j = (i << 1); j <= n; j += i) {
            ++arr[j];
        }
    }
    
    while (back < pidx) {
        if (t < n) {
            t += pn[++back];
        } else if (t > n) {
            t -= pn[front++];
        } else {
            ++cnt;
            t += pn[++back];
            t -= pn[front++];
        }
    }
    
    return !printf("%d", cnt);
}