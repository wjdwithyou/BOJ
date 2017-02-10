#include <iostream>

#define MAX_SIZE 1048576

int arr[MAX_SIZE] = { 0, };

int main(){
    int m, n;
    
    scanf("%d %d", &m, &n);
    
    arr[1] = 1;
    
    for (int i = 2; i <= n; ++i){
        if (arr[i] == 0){
            for (int j = 2 * i; j <= n; j += i){
                arr[j] = 1;
            }
            
            if (i >= m){
                printf("%d\n", i);
            }
        }
    }
    
    return 0;
}