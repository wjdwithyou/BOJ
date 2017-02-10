#include <iostream>

#define MAX_SIZE 10001

int arr[MAX_SIZE] = { 0, };

int main(){
    int t, n;
    
    for (int i = 2; i <= MAX_SIZE; ++i){
        if (arr[i] == 0){
            for (int j = 2 * i; j <= MAX_SIZE; j += i){
                arr[j] = 1;
            }
        }
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        scanf("%d", &n);
        
        for (int j = n >> 1; ; --j){
            if (arr[j] == 0 && arr[n - j] == 0){
                printf("%d %d\n", j, n - j);
                break;
            }
        }
    }
    
    return 0;
}