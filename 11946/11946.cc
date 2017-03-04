#include <iostream>

typedef struct Status {
    int chk;
    int cnt;
    int score;
}Status;

Status scoreboard[128][16];

int main() {
    char buf[4];
    int n, m, q, t, tno, qno, idx;
    
    scanf("%d %d %d", &n, &m, &q);
    
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %s", &t, &tno, &qno, buf);
        
        if (scoreboard[tno][qno].chk) {
            continue;
        }
        
        if (buf[0] == 'A') {
            ++scoreboard[tno][qno].chk;
            scoreboard[tno][0].score += 20 * scoreboard[tno][qno].cnt + t;
            ++scoreboard[tno][0].cnt;
        } else {
            ++scoreboard[tno][qno].cnt;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        idx = 1;
        
        for (int j = 1; j <= n; ++j) {
            if (scoreboard[idx][0].cnt < scoreboard[j][0].cnt) {
                idx = j;
            } else if (scoreboard[idx][0].cnt == scoreboard[j][0].cnt) {
                if (scoreboard[idx][0].score > scoreboard[j][0].score) {
                    idx = j;
                }
            } else;
        }
        
        printf("%d %d %d\n", idx, scoreboard[idx][0].cnt, scoreboard[idx][0].score);
        scoreboard[idx][0].cnt = -1;
    }
    
    return 0;
}