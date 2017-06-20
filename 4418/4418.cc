#include <iostream>
#include <cstring>

typedef struct Proposal {
    char name[128];
    double price;
    int req_num;
}Proposal;

int main() {
    char buf[128];
    Proposal max, temp;
    int n, p;
    
    for (int i = 1;; ++i) {
        scanf("%d %d", &n, &p);
        while (getchar() != '\n');
        
        if (!n && !p) {
            break;
        }
        
        max.req_num = -1;
        
        for (int j = 0; j < n; ++j) {
            fgets(buf, 128, stdin);
        }
        
        for (int j = 0; j < p; ++j) {
            fgets(temp.name, 128, stdin);
            scanf("%lf %d", &temp.price, &temp.req_num);
            while (getchar() != '\n');
            
            for (int k = 0; k < temp.req_num; ++k) {
                fgets(buf, 128, stdin);
            }
            
            if (max.req_num > temp.req_num || max.req_num == temp.req_num && max.price <= temp.price) {
                continue;
            }
            
            strcpy(max.name, temp.name);
            max.price = temp.price;
            max.req_num = temp.req_num;
        }
        
        printf("RFP #%d\n%s\n", i, max.name);
    }
    
    return 0;
}