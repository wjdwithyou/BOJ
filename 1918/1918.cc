#include <iostream>

int main() {
    char buf[1024], stack[1024];
    int idx = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] == '+' || buf[i] == '-') {
            for (int j = 0; j < 2; ++j) {
                if (idx && stack[idx - 1] != '(') {
                    printf("%c", stack[--idx]);
                }
            }
            stack[idx++] = buf[i];
        } else if (buf[i] == '*' || buf[i] == '/') {
            if (stack[idx - 1] == '*' || stack[idx - 1] == '/') {
                printf("%c", stack[--idx]);
            }
            stack[idx++] = buf[i];
        } else if (buf[i] == '(') {
            stack[idx++] = buf[i];
        } else if (buf[i] == ')') {
            while (stack[idx - 1] != '(') {
                printf("%c", stack[--idx]);
            }
            --idx;
        } else {
            printf("%c", buf[i]);
        }
    }
    
    while (idx) {
        printf("%c", stack[--idx]);
    }
    
    return 0;
}