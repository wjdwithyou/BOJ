#include <iostream>

int arr[1048576], queue[1048576];

int bfs(int*, int*, int, int, int, int, int);

int main() {
    int f, s, g, u, d;
    int front = 0, back = 0;
    
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    
    queue[back++] = s;
    
    if (bfs(&front, &back, f, u, d, g, 1) == -1) {
        printf("use the stairs");
    } else {
        printf("%d", arr[g]);
    }
    
    return 0;
}

int bfs(int* front, int* back, int f, int u, int d, int g, int cnt) {
    int temp;
    int o_back = *back;
    
    if (*front == *back) {
        return -1;
    }
    
    while (*front < o_back) {
        temp = queue[(*front)++];
        
        if (temp == g) {
            return 0;
        }
        
        if (temp + u <= f && !arr[temp + u]) {
            queue[(*back)++] = temp + u;
            arr[temp + u] = cnt;
        }
        if (temp - d >= 0 && !arr[temp - d]) {
            queue[(*back)++] = temp - d;
            arr[temp - d] = cnt;
        }
    }
    
    return bfs(front, back, f, u, d, g, ++cnt);
}