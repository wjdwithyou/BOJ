#include <iostream>

int network[128][128];

void dfs(int, int);

int main() {
    int ncom, npair, a, b;
    int cnt = 0;
    
    scanf("%d", &ncom);
    scanf("%d", &npair);
    
    for (int i = 0; i < npair; ++i) {
        scanf("%d %d", &a, &b);
        network[a][b] = network[b][a] = 1;
    }
    
    dfs(ncom, 1);
    
    for (int i = 2; i <= ncom; ++i) {
        cnt += network[i][i];
    }
    
    printf("%d", cnt);
    return 0;
}

void dfs(int ncom, int n) {
    ++network[n][n];
    
    for (int i = 1; i <= ncom; ++i) {
        if (network[n][i] && !network[i][i]) {
            dfs(ncom, i);
        }
    }
    
    return;
}