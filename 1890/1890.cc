#include <iostream>

typedef struct Node {
    int num;
    unsigned long long int route;
}Node;

Node board[128][128];

int main() {
    int n;
    
    scanf("%d", &n);
    
    board[0][0].route = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[i][j].num);
            
            for (int k = 1; k <= 9 && j >= k; ++k) {
                board[i][j].route += (board[i][j - k].num == k) ? board[i][j - k].route : 0;
            }
            for (int k = 1; k <= 9 && i >= k; ++k) {
                board[i][j].route += (board[i - k][j].num == k) ? board[i - k][j].route : 0;
            }
        }
    }
    
    printf("%llu", board[n - 1][n - 1].route);
    return 0;
}