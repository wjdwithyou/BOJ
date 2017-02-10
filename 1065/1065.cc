#include <iostream>

bool validate(int);

int main(){
    int n;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i){
        if (validate(i)){
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}

bool validate(int n){
    if (n < 100){
        return true;
    }
    else if (n == 1000){
        return false;
    }
    else{
        int a = n / 100;
        int r2 = n % 100;
        int b = r2 / 10;
        int c = r2 % 10;
        
        int t1 = a - b;
        int t2 = b - c;
        
        if (t1 == t2){
            return true;
        }
        else{
            return false;
        }
    }
}