#include <iostream>

int hash(char);

int main() {
    int cnt[4][64] = { 0 };
    char prefix[8] = "ACGT";
    char buf[64];
    int n, m, idx;
    int d = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        
        for (int j = 0; j < m; ++j) {
            ++cnt[hash(buf[j])][j];
        }
    }
    
    for (int j = 0; j < m; ++j) {
        idx = 0;
        
        for (int i = 1; i < 4; ++i) {
            if (cnt[idx][j] < cnt[i][j]) {
                idx = i;
            }
        }
        
        printf("%c", prefix[idx]);
        d += n - cnt[idx][j];
    }
    
    return !printf("\n%d", d);
}

int hash(char c) {
    switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
        default:
            return 3;
    }
}