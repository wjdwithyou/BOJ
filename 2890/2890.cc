#include <iostream>

typedef struct Team {
    int loc;
    int rank;
}Team;

char arr[64][64];

int main() {
    int temp[64] = { 0 };
    Team team[16];
    int r, c;
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; ++i) {
        scanf("%s", arr[i]);
        
        for (int j = 1; arr[i][j] != 'F'; ++j) {
            if (arr[i][j] != '.') {
                team[arr[i][j] - '0'] = { j, 0 };
                ++temp[j];
                break;
            }
        }
    }
    
    for (int k = c, r = 0; k > 0; --k) {
        if (!temp[k]) {
            continue;
        }
        
        ++r;
        
        for (int i = 1; i <= 9; ++i) {
            if (team[i].loc == k) {
                team[i].rank = r;
            }
        }
    }
    
    for (int i = 1; i <= 9; ++i) {
        printf("%d\n", team[i].rank);
    }
    
    return 0;
}