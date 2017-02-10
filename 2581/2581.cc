#include <iostream>

#define MAX_SIZE 10001

int arr[MAX_SIZE] = { 0, };

int main(){
    int m, n;
    int sum = 0;
    int min;
    bool chk = false;
    
    scanf("%d", &m);
    scanf("%d", &n);
    
    arr[1] = 1;
    
    for (int i = 2; i <= n; ++i){
        if (arr[i] == 0){
            for (int j = 2 * i; j <= n; j += i){
                arr[j] = 1;
            }
            
            if (i >= m){
                if (!chk){
                    min = i;
                    chk = true;
                }
                
                sum += i;
            }
        }
    }
    
    if (sum == 0){
        printf("-1");
    }
    else{
        printf("%d\n%d", sum, min);
    }
    
    return 0;
}