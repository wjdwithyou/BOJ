#include <iostream>

int main(void) {
    int box[1024];
    int T, j, n, r, c, idx, tmp;
    
    scanf("%d", &T);
    
    for (int Ti = 1; Ti <= T; ++Ti) {
        scanf("%d %d", &j, &n);
        
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &r, &c);
            box[i] = r * c;
        }
        
        for (int i = 0; i < n; ++i) {
            idx = i;
            
            for (int j = i + 1; j < n; ++j) {
                if (box[idx] < box[j]) {
                    idx = j;
                }
            }
            
            if (idx != i) {
                tmp = box[i];
                box[i] = box[idx];
                box[idx] = tmp;
            }
            
            j -= box[i];
            
            if (j <= 0) {
                printf("%d\n", ++i);
                break;
            }
        }
    }
    
    return 0;
}