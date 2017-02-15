#include <iostream>
#include <cstring>

int main() {
    char a[128], b[128], t[128];
    int alen, blen, tlen;
    char op;
    
    scanf("%s", a);
    
    while (getchar() != '\n');
    
    scanf("%c", &op);
    scanf("%s", b);
    
    alen = strlen(a);
    blen = strlen(b);
    
    if (op == '+') {
        if (alen == blen) {
            printf("2");
            
            for (int i = 0; i < alen - 1; ++i) {
                printf("0");
            }
        }
        else {
            if (alen < blen) {
                tlen = alen;
                alen = blen;
                blen = tlen;
                
                strcpy(t, a);
                strcpy(a, b);
                strcpy(b, t);
            }
            
            for (int i = 0; i < alen - blen; ++i) {
                printf("%c", a[i]);
            }
            for (int i = 0; i < blen; ++i) {
                printf("%c", b[i]);
            }
        }
    }
    else {
        printf("1");
        
        for (int i = 0; i < alen + blen - 2; ++i) {
            printf("0");
        }
    }
    
    return 0;
}