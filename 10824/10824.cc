#include <iostream>
#include <cstring>
#include <cmath>

int main(){
    char a[16], b[8], c[16], d[8];
    unsigned long long int ab, cd;
    int la, lc;
    
    ab = cd = 0;
    
    scanf("%s %s %s %s", a, b, c, d);
    
    strcat(a, b);
    strcat(c, d);
    
    la = strlen(a);
    lc = strlen(c);
    
    for (int i = la - 1; i >= 0; --i){
        ab += ((a[i] - '0') * static_cast<unsigned long long int>(pow(10, la - (i + 1))));
    }
    
    for (int i = lc - 1; i >= 0; --i){
        cd += ((c[i] - '0') * static_cast<unsigned long long int>(pow(10, lc - (i + 1))));
    }
    
    printf("%llu", ab + cd);
    return 0;
}