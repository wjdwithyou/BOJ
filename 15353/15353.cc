#include <iostream>
#include <cstring>

#define MAX 10000

char a[MAX + 1], b[MAX + 1], c[MAX + 1];

int main(void) {
    setbuf(stdout, NULL);
    
    int la, lb, lc, carry, t;
    
    scanf("%s %s", a, b);
    
    la = strlen(a);
    lb = strlen(b);
    lc = (la > lb) ? la : lb;
    
    carry = 0;
    
    for (--la, --lb, c[lc--] = '\0'; la >= 0 && lb >= 0; --la, --lb, --lc) {
        t = a[la] + b[lb] + carry - ('0' << 1);
        
        carry = t / 10;
        c[lc] = t % 10 + '0';
    }
    for (; la >= 0; --la, --lc) {
        t = a[la] + carry - '0';
        
        carry = t / 10;
        c[lc] = t % 10 + '0';
    }
    for (; lb >= 0; --lb, --lc) {
        t = b[lb] + carry - '0';
        
        carry = t / 10;
        c[lc] = t % 10 + '0';
    }
    
    if (carry) {
        printf("1");
    }
    
    return !printf(c);
}