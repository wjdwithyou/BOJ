#include <iostream>

int main(){
    char buf[128];
    int n;
    int sum = 0;
    
    scanf("%d", &n);
    scanf("%s", buf);
    
    for (int i = 0; i < n; ++i){
        sum += (buf[i] - '0');
    }
    
    printf("%d", sum);
    return 0;
}