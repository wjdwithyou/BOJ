#include <iostream>

int main(){
    int a, b, c, d;
    int h, m, s;
    
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &d);
    
    h = d / 3600;
    m = (d % 3600) / 60;
    s = (d % 3600) % 60;
    
    c += s;
    
    if (c >= 60){
        c -= 60;
        ++b;
    }
    
    b += m;
    
    if (b >= 60){
        b -= 60;
        ++a;
    }
    
    a += h;
    
    if (a >= 24){
        a %= 24;
    }
    
    printf("%d %d %d", a, b, c);
    return 0;
}