#include <iostream>

#define MAX 6

void selectNum(int[], int[], int, int, int);

int main() {
    int s[16], r[8];
    int k;
    
    while (1) {
        scanf("%d", &k);
        
        if (!k) {
            break;
        }
        
        for (int i = 0; i < k; ++i) {
            scanf("%d", &s[i]);
        }
        
        selectNum(s, r, k, 0, 0);
        puts("");
    }
    
    return 0;
}

void selectNum(int s[], int r[], int k, int p, int d) {
    if (d >= MAX) {
        for (int i = 0; i < MAX; ++i) {
            printf("%d ", r[i]);
        }
        puts("");
        return;
    }
    
    for (int i = p; i <= d + k - MAX; ++i) {
        r[d] = s[i];
        selectNum(s, r, k, i + 1, d + 1);
    }
    
    return;
}