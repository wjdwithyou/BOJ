#include <iostream>

typedef struct Node {
    int num;
    int cnt;
}Node;

Node arr[1024];

int main() {
    int n, c, t, idx, max;
    int k = 0;
    
    scanf("%d %d", &n, &c);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        
        for (int j = 0; j < n; ++j) {
            if (!arr[j].num) {
                arr[j] = { t, 1 };
                ++k;
                break;
            } else if (arr[j].num == t) {
                ++arr[j].cnt;
                break;
            }
        }
    }
    
    for (int i = 0; i < k; ++i) {
        max = 0;
        
        for (int j = 0; j < k; ++j) {
            if (max < arr[j].cnt) {
                idx = j;
                max = arr[idx].cnt;
            }
        }
        
        for (int j = 0; j < arr[idx].cnt; ++j) {
            printf("%d ", arr[idx].num);
        }
        
        arr[idx].cnt = 0;
    }
    
    return 0;
}