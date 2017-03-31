#include <iostream>

#define NUM_ALPHA 26

int pn[2048];

int main() {
    char buf[32];
    int sum = 0;
    
    for (int i = 2; i <= 20 * NUM_ALPHA; ++i) {
        if (!pn[i]) {
            for (int j = 2 * i; j <= 40 * NUM_ALPHA; j += i) {
                ++pn[j];
            }
        }
    }
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        sum += (buf[i] > 'a') ? buf[i] - 'a' + 1 : buf[i] - 'A' + NUM_ALPHA + 1;
    }
    
    printf("It is%s a prime word.", (pn[sum]) ? " not" : "");
    return 0;
}