#include <iostream>

int main(){
    int asc[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int desc[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int arr[8];
    int acnt = 0;
    int dcnt = 0;
    
    for (int i = 0; i < 8; ++i){
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 8; ++i){
        if (arr[i] == asc[i]){
            ++acnt;
        }
        else if (arr[i] == desc[i]){
            ++dcnt;
        }
        else{
            break;
        }
    }
    
    if (acnt == 8){
        printf("ascending");
    }
    else if (dcnt == 8){
        printf("descending");
    }
    else{
        printf("mixed");
    }
    
    return 0;
}