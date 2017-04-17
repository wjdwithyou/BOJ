#include <iostream>

char arr[512][512];

int main() {
    int counter[8] = { 0, };
    int m, n, tm, tn, k;
    
    scanf("%d %d", &m, &n);
    
    tm = 5 * m + 1;
    tn = 5 * n + 1;
    
    for (int i = 0; i < tm; ++i) {
        scanf("%s", arr[i]);
    }
    
    for (int i = 1; i < tm; i += 5) {
        for (int j = 1; j < tn; j += 5) {
            for (k = 0; arr[i + k][j] != '.' && k < 4; ++k);
            ++counter[k];
        }
    }
    
    for (int i = 0; i < 5; ++i) {
        printf("%d ", counter[i]);
    }
    
    return 0;
}