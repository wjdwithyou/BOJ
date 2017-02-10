#include <iostream>

int main(){
    int cnt_arr[10] = {0,};
    int a, b, c, n;
    bool chk = false;
    
    scanf("%d %d %d", &a, &b, &c);
    
    n = a * b * c;
    
    for (int i = 100000000; i >= 10; i /= 10){
        int q = n / i;
        
        n %= i;
        
        if (q == 0 && !chk){
            continue;
        }
        
        if (q != 0 && !chk){
            chk = true;
        }
        
        ++cnt_arr[q];
    }
    
    ++cnt_arr[n];
    
    for (int i = 0; i < 10; ++i){
        printf("%d\n", cnt_arr[i]);
    }
    
    return 0;
}