#include <iostream>

int main() {
    int sh, sm, ss, eh, em, es;
    
    for (int i = 0; i < 3; ++i) {
        scanf("%d %d %d %d %d %d", &sh, &sm, &ss, &eh, &em, &es);
        
        if (ss > es) {
            es += 60;
            --em;
        }
        
        es -= ss;
        
        if (sm > em) {
            em += 60;
            --eh;
        }
        
        em -= sm;
        eh -= sh;
        
        printf("%d %d %d\n", eh, em, es);
    }
    
    return 0;
}