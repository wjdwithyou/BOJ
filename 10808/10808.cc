#include <iostream>

#define NUM_ALPHA 26

int main() {
    char buf[128];
    int alpha[NUM_ALPHA] = { 0, };
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        ++alpha[buf[i] - 'a'];
    }
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        printf("%d ", alpha[i]);
    }
    
    return 0;
}