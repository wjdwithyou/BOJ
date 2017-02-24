#include <iostream>

#define KAPREKAR 6174
#define MAX_NUM 4

int main() {
    char buf[8];
    int t, idx, max, min;
    char temp;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%s", buf);
        
        for (int a = 0;; ++a) {
            if (atoi(buf) == KAPREKAR) {
                printf("%d\n", a);
                break;
            }
            
            for (int j = 0; j < MAX_NUM; ++j) {
                idx = j;
                
                for (int k = j + 1; k < MAX_NUM; ++k) {
                    if (buf[idx] < buf[k]) {
                        idx = k;
                    }
                }
                
                temp = buf[j];
                buf[j] = buf[idx];
                buf[idx] = temp;
            }
            
            max = atoi(buf);
            
            for (int j = 0; j <= 1; ++j) {
                temp = buf[j];
                buf[j] = buf[(MAX_NUM - 1) - j];
                buf[(MAX_NUM - 1) - j] = temp;
            }
            
            min = atoi(buf);
            
            sprintf(buf, "%04d", max - min);
        }
    }
    
    return 0;
}