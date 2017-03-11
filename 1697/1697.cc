#include <iostream>

#define MAX 100000

int arr[131072], queue[131072];

void bfs(int*, int*, int);

int main() {
    int n, k;
    int front = 0, back = 0;
    
    scanf("%d %d", &n, &k);
    
    queue[back++] = n;
    arr[n] = 0;
    
    bfs(&front, &back, k);
    
    printf("%d", arr[k]);
    return 0;
}

void bfs(int* front, int* back, int k) {
    int temp = queue[(*front)++];
    
    if (temp == k) {
        return;
    }
    
    if (temp - 1 >= 0 && !arr[temp - 1]) {
        queue[(*back)++] = temp - 1;
        arr[temp - 1] = arr[temp] + 1;
    }
    if (temp + 1 <= MAX && !arr[temp + 1]) {
        queue[(*back)++] = temp + 1;
        arr[temp + 1] = arr[temp] + 1;
    }
    if ((temp << 1) <= MAX && !arr[temp << 1]) {
        queue[(*back)++] = (temp << 1);
        arr[temp << 1] = arr[temp] + 1;
    }
    
    return bfs(front, back, k);
}