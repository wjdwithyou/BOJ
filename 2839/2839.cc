#include <iostream>

int main(){
    int all;
    int n_five, n_three;
    int r_five, r_three;
    
    scanf("%d", &all);
    
    for (int i = 0; i <= (all / 5); ++i){
        n_five = (all / 5) - i;
        r_five = all - (5 * n_five);
        n_three = r_five / 3;
        r_three = r_five % 3;
        
        if (r_three == 0){
            printf("%d", n_five + n_three);
            return 0;
        }
    }
    
    printf("%d", -1);
    return 0;
}