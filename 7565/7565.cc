#include <iostream>
#include <cstring>

typedef struct Problem {
    int chk;
    int cnt;
}Problem;

typedef struct Team {
    char name[16];
    Problem problem[16];
    int correct;
    int score;
    int rank;
}Team;

Team* team[32];

int main() {
    char c[4], d[16];
    int t, n, k, m, a, b, idx;
    Team* temp;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            team[j] = static_cast<Team*>(calloc(1, sizeof(Team)));
            scanf("%s", team[j]->name);
        }
        
        scanf("%d %d", &k, &m);
        
        for (int j = 0; j < m; ++j) {
            scanf("%d %d %s %s", &a, &b, c, d);
            
            for (int x = 0; x < n; ++x) {
                if (!strcmp(team[x]->name, d)) {
                    if (!team[x]->problem[a].chk) {
                        if (c[0] == 'Y') {
                            ++team[x]->problem[a].chk;
                            ++team[x]->correct;
                            team[x]->score += 20 * team[x]->problem[a].cnt + b;    
                        } else {
                            ++team[x]->problem[a].cnt;
                        }
                    }
                    
                    break;
                }
            }
        }
        
        for (int j = 0; j < n; ++j) {
            idx = j;
            
            for (int x = j + 1; x < n; ++x) {
                if (team[idx]->correct < team[x]->correct ||
                    team[idx]->correct == team[x]->correct && team[idx]->score > team[x]->score ||
                    team[idx]->correct == team[x]->correct && team[idx]->score == team[x]->score && strcmp(team[idx]->name, team[x]->name) > 0) {
                    
                    idx = x;
                }
            }
            
            temp = team[j];
            team[j] = team[idx];
            team[idx] = temp;
            
            if (!j) {
                team[j]->rank = 1;
                continue;
            }
            
            team[j]->rank = (team[j]->correct == team[j - 1]->correct && team[j]->score== team[j - 1]->score) ? team[j - 1]->rank : j + 1;
        }
        
        for (int j = 0; j < n; ++j) {
            printf("%2d. %-8s %d %4d\n", team[j]->rank, team[j]->name, team[j]->correct, team[j]->score);
            free(team[j]);
        }
        
        puts("");
    }
    
    return 0;
}