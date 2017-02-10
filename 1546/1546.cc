#include <iostream>

int main(){
    int subject[1024];
    int n;
    int max = -1;
    float sum = 0.0f;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i){
        scanf("%d", &subject[i]);
        
        if (subject[i] > max){
            max = subject[i];
        }
    }
    
    for (int i = 0; i < n; ++i){
        sum += (100 * (float)subject[i] / max);
    }
    
    printf("%.2f", (float)sum / n);
    return 0;
}