#include <iostream>
#include <cstring>

char a[16384], b[16384], r[16384];

void checkCarry(char*, int*);

int main() {
    int ldx, sdx, rdx;
    int carry = 0, swp = 0;
    
    scanf("%s %s", a, b);
    
    ldx = strlen(a) - 1;
    sdx = strlen(b) - 1;
    
    if (ldx < sdx) {
        ldx ^= sdx;
        sdx ^= ldx;
        ldx ^= sdx;
        
        swp = 1;
    }
    
    for (; sdx >= 0; --ldx, --sdx) {
        r[ldx] = ((swp) ? a[sdx] + b[ldx] : a[ldx] + b[sdx]) + carry - '0';
        checkCarry(&r[ldx], &carry);
    }
    
    for (; ldx >= 0; --ldx) {
        r[ldx] = ((swp) ? b[ldx] : a[ldx]) + carry;
        checkCarry(&r[ldx], &carry);
    }
    
    rdx = strlen(r);
    
    if (carry) {
        printf("1");
    }
    
    for (int i = 0; i < rdx; ++i) {
        printf("%c", r[i]);
    }
    
    return 0;
}

void checkCarry(char* r, int* carry) {
    if (*r > '9') {
        *r -= 10;
        *carry = 1;
    }
    else {
        *carry = 0;
    }
    
    return;
}