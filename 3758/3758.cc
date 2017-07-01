#include <iostream>

struct Team {
    int score[128];
    int num;
    int sum;
    int cnt;
    int last;
};

Team* team[128];

int main() {
    int tt, n, kk, t, m, ii, jj, ss, idx;
    Team* temp;
    
    scanf("%d", &tt);
    
    for (int i = 0; i < tt; ++i) {
        scanf("%d %d %d %d", &n, &kk, &t, &m);
        
        for (int j = 1; j <= n; ++j) {
            team[j] = static_cast<Team*>(malloc(sizeof(Team)));
            
            for (int k = 1; k <= kk; ++k) {
                team[j]->score[k] = 0;
            }
            
            team[j]->num = j;
            team[j]->sum = team[j]->cnt = team[j]->last = 0;
        }
        
        for (int j = 1; j <= m; ++j) {
            scanf("%d %d %d", &ii, &jj, &ss);
            
            if (team[ii]->score[jj] < ss) {
                team[ii]->sum += ss - team[ii]->score[jj];
                team[ii]->score[jj] = ss;
            }
            
            ++team[ii]->cnt;
            team[ii]->last = j;
        }
        
        for (int j = 1; j <= n; ++j) {
            idx = j;
            
            for (int k = j + 1; k <= n; ++k) {
                if (team[idx]->sum > team[k]->sum);
                else if (team[idx]->sum == team[k]->sum && team[idx]->cnt < team[k]->cnt);
                else if (team[idx]->sum == team[k]->sum && team[idx]->cnt == team[k]->cnt && team[idx]->last < team[k]->last);
                else {
                    idx = k;
                }
            }
            
            if (idx != j) {
                temp = team[j];
                team[j] = team[idx];
                team[idx] = temp;
            }
            
            if (team[j]->num == t) {
                printf("%d\n", j);
                break;
            }
        }
        
        for (int j = 1; j <= n; ++j) {
            free(team[j]);
        }
    }
    
    return 0;
}