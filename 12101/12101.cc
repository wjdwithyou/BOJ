#include <iostream>

int method[512][16];

void getMethod(int*, int[], int, int, int);

int main() {
    int stack[16];
    int n, k;
    int midx = 1, sidx = 0;
    
    scanf("%d %d", &n, &k);
    
    getMethod(&midx, stack, sidx, n, k);
    
    if (k >= midx) {
        printf("-1");
    }
    else {
        printf("%d", method[k][0]);
        
        for (int i = 1; method[k][i] != 0; ++i) {
            printf("+%d", method[k][i]);
        }
    }
    
    return 0;
}

void getMethod(int* midx, int stack[], int sidx, int n, int k) {
    int sum;
    int cnt = 0;
    
    if (k < *midx) {
        return;
    }
    
    for (int i = 1; i <= 3; ++i, --sidx) {
        stack[sidx++] = i;
        sum = 0;
        
        for (int j = 0; j < sidx; ++j) {
            sum += stack[j];
        }
        
        if (sum < n) {
            getMethod(midx, stack, sidx, n, k);
            continue;
        }
        
        if (sum == n) {
            for (int j = 0; j < sidx; ++j) {
                method[*midx][j] = stack[j];
            }
            
            ++(*midx);
        }
        
        break;
    }
}