#include <iostream>

int main(){
    int t[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
    char buf[16];
    int sum = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i){
        int idx = buf[i] - 'A';
        sum += t[idx];
    }
    
    printf("%d", sum);
    return 0;
}