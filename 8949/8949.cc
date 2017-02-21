#include <iostream>
#include <cstring>

int main() {
    int stack[8];
    char a[8], b[8];
    int sdx, adx, bdx;
    
    scanf("%s %s", a, b);
    
    sdx = 0;
    adx = strlen(a) - 1;
    bdx = strlen(b) - 1;
    
    while (adx >= 0 || bdx >= 0) {
        if (adx < 0) {
            stack[sdx++] = b[bdx--] - '0';
        } else if (bdx < 0) {
            stack[sdx++] = a[adx--] - '0';
        } else {
            stack[sdx++] = a[adx--] + b[bdx--] - (2 * '0');
        }
    }
    
    for (int i = sdx - 1; i >= 0; --i) {
        printf("%d", stack[i]);
    }
    
    return 0;
}