#include <iostream>

#define NUM_ALPHA 26

int main() {
    int alpha[32] = { 0, };
    char buf[32];
    int n;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        ++alpha[buf[0] - 'a'];
    }
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        if (alpha[i] >= 5) {
            printf("%c", i + 'a');
            ++cnt;
        }
    }
    
    if (!cnt) {
        printf("PREDAJA");
    }
    
    return 0;
}