#include <iostream>

typedef struct Node {
    int base[4];
    int no;
    int sum;
}Node;

int main() {
    Node candidate[4] = { 0, };
    Node temp;
    int n, t, idx, k;
    
    for (int i = 1; i <= 3; ++i) {
        candidate[i].no = i;
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            scanf("%d", &t);
            
            ++candidate[j].base[t];
            candidate[j].sum += t;
        }
    }
    
    for (int i = 1; i <= 3; ++i) {
        idx = i;
        
        for (int j = i + 1; j <= 3; ++j) {
            if (candidate[idx].sum < candidate[j].sum) {
                idx = j;
            }
        }
        
        temp = candidate[i];
        
        for (int j = 1; j <= 3; ++j) {
            temp.base[j] = candidate[i].base[j];
        }
        
        candidate[i] = candidate[idx];
        
        for (int j = 1; j <= 3; ++j) {
            candidate[i].base[j] = candidate[idx].base[j];
        }
        
        candidate[idx] = temp;
        
        for (int j = 1; j <= 3; ++j) {
            candidate[idx].base[j] = temp.base[j];
        }
    }
    
    if (candidate[1].sum == candidate[2].sum) {
        int i;
        
        for (i = 3; i > 1; --i) {
            if (candidate[1].base[i] == candidate[2].base[i]) {
                continue;
            }
            
            k = (candidate[1].base[i] > candidate[2].base[i]) ? 1 : 2;
            
            printf("%d %d", candidate[k].no, candidate[k].sum);
            break;
        }
        
        if (i == 1) {
            printf("0 %d", candidate[1].sum);
        }
    }
    else {
        printf("%d %d", candidate[1].no, candidate[1].sum);
    }
    
    return 0;
}