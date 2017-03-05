#include <iostream>

typedef struct State {
    int next[2];
    int finite;
}State;

State state[16] = {
    { { 7, 1 }, 0 },
    { { 2, 9 }, 0 },
    { { 3, 9 }, 0 },
    { { 3, 4 }, 0 },
    { { 7, 5 }, 1 },
    { { 6, 5 }, 1 },
    { { 3, 8 }, 0 },
    { { 9, 8 }, 0 },
    { { 7, 1 }, 1 },
    { { 9, 9 }, 0 }
};

int main() {
    char buf[256];
    int t, temp;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        temp = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            temp = state[temp].next[buf[j] - '0'];
        }
        
        puts((state[temp].finite) ? "YES" : "NO");
    }
    
    return 0;
}