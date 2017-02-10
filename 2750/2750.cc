#include <iostream>

#define BUF_SIZE 1024

int main(){
    int arr[BUF_SIZE];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n; ++i){
        int idx, temp;
        int min = BUF_SIZE;
        
        for (int j = i; j < n; ++j){
            if (arr[j] < min){
                idx = j;
                min = arr[j];
            }
        }
        
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    
    for (int i = 0; i < n; ++i){
        printf("%d\n", arr[i]);
    }
    
    return 0;
}