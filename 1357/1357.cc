#include <iostream>
#include <cstring>

int main() {
    char buf[4][8];
    int idx;
    int sum = 0;
    char temp;
    
    for (int i = 1; i <= 2; ++i) {
        scanf("%s", buf[i]);
        
        idx = strlen(buf[i]) - 1;
        
        for (int j = 0; j < idx; ++j, --idx) {
            temp = buf[i][j];
            buf[i][j] = buf[i][idx];
            buf[i][idx] = temp;
        }
        
        sum += atoi(buf[i]);
    }
    
    sprintf(buf[0], "%d", sum);
    
    idx = strlen(buf[0]) - 1;
    
    for (int j = 0; j < idx; ++j, --idx) {
        temp = buf[0][j];
        buf[0][j] = buf[0][idx];
        buf[0][idx] = temp;
    }
    
    printf("%d", atoi(buf[0]));
    return 0;
}