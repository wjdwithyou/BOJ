#include <iostream>
#include <cstring>

char arr[128][128];
char buf[16384];

int main() {
    char temp[8][128];
    int nfox[128];
    int t, idx, tdx;
    char* ptr;
    
    scanf("%d", &t);
    while (getchar() != '\n');
    
    for (int i = 0; i < t; ++i) {
        idx = 0;
        
        fgets(buf, 16384, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        ptr = strtok(buf, " ");
        strcpy(arr[idx++], ptr);
        
        while (ptr = strtok(NULL, " ")) {
            strcpy(arr[idx++], ptr);
        }
        
        memset(nfox, 0, sizeof(nfox));
        
        while (true) {
            tdx = 0;
            
            fgets(buf, 16384, stdin);
            buf[strlen(buf) - 1] = '\0';
            
            ptr = strtok(buf, " ");
            strcpy(temp[tdx++], ptr);
            
            while (ptr = strtok(NULL, " ")) {
                strcpy(temp[tdx++], ptr);
            }
            
            if (tdx != 3) {
                break;
            }
            
            for (int j = 0; j < idx; ++j) {
                if (!strcmp(temp[2], arr[j])) {
                    ++nfox[j];
                }
            }
        }
        
        for (int j = 0; j < idx; ++j) {
            if (!nfox[j]) {
                printf("%s ", arr[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}