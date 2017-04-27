#include <iostream>

#define DIV 1000

int matrix[64][8][8];

int main() {
    int result[8][8], temp[8][8];
    int arr[64];
    long long b;
    int n;
    int front = 0, back = 0;
    
    scanf("%d %lld", &n, &b);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = (i == j);
        }
    }
    
    for (long long i = 0, j = b; j; ++i, j >>= 1) {
        if (j & 1) {
            arr[back++] = static_cast<int>(i);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[0][i][j]);
        }
    }
    
    for (int z = 0; front < back; ++z) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    matrix[z + 1][i][j] += matrix[z][i][k] * matrix[z][k][j];
                    matrix[z + 1][i][j] %= DIV;
                }
            }
        }
        
        if (arr[front] != z) {
            continue;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[i][j] = 0;
                
                for (int k = 0; k < n; ++k) {
                    temp[i][j] += result[i][k] * matrix[z][k][j];
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = temp[i][j] % DIV;
            }
        }
        
        ++front;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", result[i][j]);
        }
        puts("");
    }
    
    return 0;
}