#include <iostream>

#define MAX_SIZE 262144

int arr[MAX_SIZE] = { 0, };

int main(){
    int n, cnt;
    
    arr[1] = 1;
    
    for (int i = 2; i <= MAX_SIZE; ++i){
        if (arr[i] == 0){
            for (int j = 2 * i; j <= MAX_SIZE; j += i){
                arr[j] = 1;
            }
        }
    }
    
    while (true){
        scanf("%d", &n);
        
        if (n == 0){
            break;
        }
        
        cnt = 0;
        
        for (int i = n + 1; i <= 2 * n; ++i){
            if (arr[i] == 0){
                ++cnt;
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}