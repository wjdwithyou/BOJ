#include <iostream>

#define MAX_SIZE 1024

int main(){
    int arr[MAX_SIZE] = { 0, };
    int n, t;
    int cnt = 0;
    
    scanf("%d", &n);
    
    arr[1] = 1;
    
    for (int i = 2; i < MAX_SIZE; ++i){
        if (arr[i] == 0){
            for (int j = 2 * i; j < MAX_SIZE; j += i){
                arr[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; ++i){
        scanf("%d", &t);
        
        if (arr[t] == 0){
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}