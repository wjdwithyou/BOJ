#include <iostream>

unsigned long long int file[1024];

int main() {
    unsigned long long int n, cluster_size;
    unsigned long long int cnt = 0;
    
    scanf("%llu", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%llu", &file[i]);
    }
    
    scanf("%llu", &cluster_size);
    
    for (int i = 0; i < n; ++i) {
        cnt += file[i] / cluster_size;
        cnt += (file[i] % cluster_size != 0);
    }
    
    printf("%llu", cnt * cluster_size);
    return 0;
}