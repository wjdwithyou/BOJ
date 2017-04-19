#include <iostream>

int arr[1024];

void inOrder(int, int);

int main() {
    int k, max;
    int idx = 1;
    
    scanf("%d", &k);
    
    max = 1 << k;
    
    inOrder(max - 1, 1);
    
    for (int i = 1; i < max; i <<= 1) {
        for (int j = 0; j < i; ++j) {
            printf("%d ", arr[idx++]);
        }
        puts("");
    }
    
    return 0;
}

void inOrder(int max, int idx) {
    if (max < idx) {
        return;
    }
    
    inOrder(max, idx << 1);
    
    scanf("%d", &arr[idx]);
    
    inOrder(max, (idx << 1) + 1);
    
    return;
}