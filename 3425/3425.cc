#include <iostream>
#include <cstring>

char opcode[131072][16];
long long stack[1024];

int main() {
    long long num1, num2;
    int n, stack_idx, err;
    int quit = 0;
    
    while (true) {
        for (int i = 0;; ++i) {
            fgets(opcode[i], 16, stdin);
            opcode[i][strlen(opcode[i]) - 1] = '\0';
            
            if (opcode[i][0] == 'E' || opcode[i][0] == 'Q') {
                if (opcode[i][0] == 'Q') {
                    ++quit;
                }
                
                break;
            }
        }
        
        if (quit) {
            break;
        }
        
        scanf("%d", &n);
        
        for (int i = 0; i < n; ++i) {
            stack_idx = err = 0;
            
            scanf("%lld", &stack[stack_idx++]);
            
            for (int j = 0; !err && opcode[j][0] != 'E'; ++j) {
                switch (opcode[j][0]) {
                    case 'A':    // add
                        if (stack_idx < 2) {
                            ++err;
                        } else {
                            num1 = stack[--stack_idx];
                            num2 = stack[--stack_idx];
                            stack[stack_idx++] = num2 + num1;
                        }
                        break;
                    case 'D':
                        if (opcode[j][1] == 'I') {    // div
                            if (stack_idx < 2) {
                                ++err;
                            } else {
                                num1 = stack[--stack_idx];
                                num2 = stack[--stack_idx];
                                
                                if (!num1) {
                                    ++err;
                                } else {
                                    stack[stack_idx++] = num2 / num1;
                                }
                            }
                        } else {    // dup
                            if (!stack_idx) {
                                ++err;
                            } else {
                                num1 = stack[--stack_idx];
                                stack[stack_idx++] = num1;
                                stack[stack_idx++] = num1;
                            }
                        }
                        break;
                    case 'I':    // inv
                        if (!stack_idx) {
                            ++err;
                        } else {
                            num1 = stack[--stack_idx];
                            stack[stack_idx++] = -num1;
                        }
                        break;
                    case 'M':
                        if (stack_idx < 2) {
                            ++err;
                        } else {
                            num1 = stack[--stack_idx];
                            num2 = stack[--stack_idx];
                            
                            if (opcode[j][1] == 'O') {    // mod
                                if (!num1) {
                                    ++err;
                                } else {
                                    stack[stack_idx++] = num2 % num1;
                                }
                            } else {    // mul
                                stack[stack_idx++] = num2 * num1;
                            }
                        }
                        break;
                    case 'N':    // num X
                        stack[stack_idx++] = atoi(&opcode[j][4]);
                        break;
                    case 'P':    // pop
                        if (!stack_idx) {
                            ++err;
                        } else {
                            --stack_idx;
                        }
                        break;
                    case 'S':
                        if (stack_idx < 2) {
                            ++err;
                        } else {
                            num1 = stack[--stack_idx];
                            num2 = stack[--stack_idx];
                            
                            if (opcode[j][1] == 'U') {    // sub
                                stack[stack_idx++] = num2 - num1;
                            } else {    // swp
                                stack[stack_idx++] = num1;
                                stack[stack_idx++] = num2;
                            }
                        }
                        break;
                    default:
                        break;
                }
                
                if (stack[stack_idx - 1] < -1000000000 || stack[stack_idx - 1] > 1000000000) {
                    ++err;
                }
            }
            
            if (err || stack_idx != 1) {
                puts("ERROR");
            } else {
                printf("%lld\n", stack[--stack_idx]);
            }
        }
        
        fgets(opcode[0], 16, stdin);
        puts("");
    }
    
    return 0;
}