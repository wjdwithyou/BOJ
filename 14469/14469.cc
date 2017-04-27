#include <iostream>

typedef struct Cow {
    int arrived;
    int time;
}Cow;

int main() {
    Cow cow[128];
    Cow temp;
    int n, idx;
    int end = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &cow[i].arrived, &cow[i].time);
    }
    
    for (int i = 0; i < n; ++i) {
        idx = i;
        
        for (int j = i + 1; j < n; ++j) {
            if (cow[idx].arrived > cow[j].arrived) {
                idx = j;
            }
        }
        
        temp = cow[i];
        cow[i] = cow[idx];
        cow[idx] = temp;
        
        end = cow[i].time + ((end < cow[i].arrived) ? cow[i].arrived : end);
    }
    
    return !printf("%d", end);
}