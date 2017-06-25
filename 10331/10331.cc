#include <iostream>
#include <cstring>

void _pop(int[], char[], int*, int*);

int main() {
    char buf[32];
    int _operand[16], operand_stack[16];
    char _operator[16], operator_stack[2];
    char* str;
    int answer, first, second;
    int operand_num = 0, operator_num = 0, operand_stack_idx = 0, operator_stack_idx = 0;
    
    scanf("%s %d", buf, &answer);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] == '+' || buf[i] == '*') {
            _operator[operator_num++] = buf[i];
        }
    }
    
    str = strtok(buf, "+*");
    
    do {
        _operand[operand_num++] = atoi(str);
    } while (str = strtok(NULL, "+*"));
    
    operand_stack[operand_stack_idx++] = second = _operand[0];
    
    for (int i = 0; i < operator_num; ++i) {
        if (!operator_stack_idx) {
            operator_stack[operator_stack_idx++] = _operator[i];
        } else {
            if (operator_stack[operator_stack_idx - 1] == _operator[i]) {
                --operand_stack_idx;
                
                if (_operator[i] == '+') {
                    operand_stack[operand_stack_idx - 1] += operand_stack[operand_stack_idx];
                } else {
                    operand_stack[operand_stack_idx - 1] *= operand_stack[operand_stack_idx];
                }
            } else {
                if (_operator[i] == '+') {
                    _pop(operand_stack, operator_stack, &operand_stack_idx, &operator_stack_idx);
                }
                
                operator_stack[operator_stack_idx++] = _operator[i];
            }
        }
        
        operand_stack[operand_stack_idx++] = _operand[i + 1];
    }
    
    _pop(operand_stack, operator_stack, &operand_stack_idx, &operator_stack_idx);
    
    first = operand_stack[0];
    
    for (int i = 0; i < operator_num; ++i) {
        if (_operator[i] == '+') {
            second += _operand[i + 1];
        } else {
            second *= _operand[i + 1];
        }
    }
    
    if (first == answer && second == answer) {
        printf("U");
    } else if (first == answer) {
        printf("M");
    } else if (second == answer) {
        printf("L");
    } else {
        printf("I");
    }
    
    return 0;
}

void _pop(int operand_stack[], char operator_stack[], int* operand_stack_idx, int* operator_stack_idx) {
    while (*operator_stack_idx) {
        --(*operand_stack_idx);
        
        if (operator_stack[--(*operator_stack_idx)] == '+') {
            operand_stack[*operand_stack_idx - 1] += operand_stack[*operand_stack_idx];
        } else {
            operand_stack[*operand_stack_idx - 1] *= operand_stack[*operand_stack_idx];
        }
    }
    
    return;
}