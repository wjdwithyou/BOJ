#include <iostream>

int main() {
    int t, hp, mp, ap, dp, dhp, dmp, dap, ddp;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &ap, &dp, &dhp, &dmp, &dap, &ddp);
        
        hp += dhp;
        
        if (hp < 1) {
            hp = 1;
        }
        
        mp += dmp;
        
        if (mp < 1) {
            mp = 1;
        }
        
        ap += dap;
        
        if (ap < 0) {
            ap = 0;
        }
        
        dp += ddp;
        
        printf("%d\n", hp + 5 * mp + 2 * ap + 2 * dp);
    }
    
    return 0;
}