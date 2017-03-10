#include <iostream>
#include <cstring>

#define MAX 20

int main() {
    int arr[32] = { 0, };
    char buf[16];
    char *opcode, *operand;
    int m, n;
    
    scanf("%d", &m);
    while (getchar() != '\n');
    
    for (int i = 0; i < m; ++i) {
        fgets(buf, 16, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        opcode = strtok(buf, " ");
        operand = strtok(NULL, " ");
        
        n = (operand) ? atoi(operand) : 1;
        
        switch (opcode[0]) {
            case 'a':
                if (opcode[1] == 'd') {    // add
                    arr[n] = 1;
                } else {    // all
                    for (; n <= MAX; ++n) {
                        arr[n] = 1;
                    }
                }
                break;
            case 'c':    // check
                printf("%d\n", arr[n]);
                break;
            case 'e':    // empty
                for (; n <= MAX; ++n) {
                    arr[n] = 0;
                }
                break;
            case 'r':    // remove
                arr[n] = 0;
                break;
            case 't':    // toggle
                arr[n] = (arr[n]) ? 0 : 1;
                break;
            default:
                break;
        }
    }
    
    return 0;
}