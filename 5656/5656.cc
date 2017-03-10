#include <iostream>

int main() {
    char opcode[4];
    int a, b, r;
    
    for (int i = 1, e = 0;; ++i) {
        scanf("%d %s %d", &a, opcode, &b);
        
        switch (opcode[0]) {
            case '>':
                r = (opcode[1] == '=') ? (a >= b) : (a > b);
                break;
            case '<':
                r = (opcode[1] == '=') ? (a <= b) : (a < b);
                break;
            case '=':
                r = (a == b);
                break;
            case '!':
                r = (a != b);
                break;
            default:
                ++e;
                break;
        }
        
        if (e) {
            break;
        }
        
        printf("Case %d: %s\n", i, (r) ? "true" : "false");
    }
    
    return 0;
}