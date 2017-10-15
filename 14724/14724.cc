#include <iostream>

#define N 9

int main() {
    char club[16][16] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };
    int n, t, idx;
    
    scanf("%d", &n);
    
    for (int i = 0, max = 0; i < N; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &t);
            
            if (max < t) {
                max = t;
                idx = i;
            }
        }
    }
    
    return !printf("%s", club[idx]);
}