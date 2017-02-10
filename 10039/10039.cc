#include <iostream>

int main(){
    int arr[5];
    int sum = 0;
    
    for (int i = 0; i < 5; ++i){
        scanf("%d", &arr[i]);
        
        sum += (arr[i] < 40)? 40: arr[i];
    }
    
    printf("%d", sum / 5);
    return 0;
}