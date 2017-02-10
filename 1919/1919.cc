#include <iostream>

#define ALPHA_NUM 26

int main() {
    char buf[1024];
    int alpha[ALPHA_NUM] = { 0, };
    int check[ALPHA_NUM] = { 0, };
    int idx;
    int sum = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        idx = buf[i] - 'a';
        
        if (!check[idx]) {
            ++check[idx];
        }
        
        ++alpha[idx];
    }
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        idx = buf[i] - 'a';
        
        if (!check[idx]) {
            ++alpha[idx];
        }
        else {
            if (--alpha[idx] == 0) {
                --check[idx];
            }
        }
    }
    
    for (int i = 0; i < ALPHA_NUM; ++i) {
        sum += alpha[i];
    }
    
    printf("%d", sum);
    return 0;
}