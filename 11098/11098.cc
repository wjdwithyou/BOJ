#include <iostream>
#include <cstring>

typedef struct Player {
    char name[32];
    int price;
}Player;

int main() {
    Player max, temp;
    int n, p;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        memset(max.name, 0, sizeof(max.name));
        max.price = -1;
        
        scanf("%d", &p);
        
        for (int j = 0; j < p; ++j) {
            scanf("%d %s", &temp.price, temp.name);
            
            if (max.price < temp.price) {
                strcpy(max.name, temp.name);
                max.price = temp.price;
            }
        }
        
        puts(max.name);
    }
    
    return 0;
}