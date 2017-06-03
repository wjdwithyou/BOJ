#include <iostream>

int main() {
    char robot[16][32];
    int t, n, r, s, p, winner, alive;
    char c;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        winner = 0;
        
        scanf("%d", &n);
        
        for (int j = 1; j <= n; ++j) {
            robot[j][0] = 0;
            scanf("%s", &robot[j][1]);
        }
        
        for (int k = 1; robot[1][k] != '\0'; ++k) {
            r = s = p = 0;
            
            for (int j = 1; j <= n; ++j) {
                if (robot[j][0]) {
                    continue;
                }
                
                if (robot[j][k] == 'R') {
                    ++r;
                } else if (robot[j][k] == 'S') {
                    ++s;
                } else {
                    ++p;
                }
            }
            
            if (r && s && p || r && !s && !p || !r && s && !p || !r && !s && p) {
                continue;
            }
            
            alive = 0;
            c = (!r) ? 'S': ((!s) ? 'P' : 'R');
            
            for (int j = 1; j <= n; ++j) {
                if (robot[j][0]) {
                    continue;
                }
                
                if (robot[j][k] == c) {
                    ++alive;
                    winner = j;
                } else {
                    ++robot[j][0];
                }
            }
            
            if (alive < 2) {
                break;
            }
            
            winner = !winner;
        }
        
        printf("%d\n", winner);
    }
    
    return 0;
}