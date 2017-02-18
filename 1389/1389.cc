#include <iostream>
#include <cstring>

int relation[128][128];

void bfs(int[], int, int*, int*, int[]);

int main() {
    int queue[128], kbn[128];
    int n, m, a, b, front, back, sum, idx;
    int min = 16384;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        relation[a][b] = relation[b][a] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        memset(kbn, 0, sizeof(kbn));
        sum = 0;
        
        front = back = 0;
        queue[back++] = i;
        
        bfs(queue, n, &front, &back, kbn);
        
        for (int j = 1; j <= n; ++j) {
            sum += (i == j) ? 0 : kbn[j];
        }
        
        if (min > sum) {
            idx = i;
            min = sum;
        }
    }
    
    printf("%d", idx);
    return 0;
}

void bfs(int queue[], int n, int* front, int* back, int kbn[]) {
    if (*front == *back) {
        return;
    }
    
    int temp = queue[(*front)++];
    
    for (int i = 1; i <= n; ++i) {
        if (relation[temp][i] && !kbn[i]) {
            queue[(*back)++] = i;
            kbn[i] = kbn[temp] + 1;
        }
    }
    
    return bfs(queue, n, front, back, kbn);
}