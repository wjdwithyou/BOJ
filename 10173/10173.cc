#include <iostream>
#include <cstring>

int main() {
    char nemo[4] = { 'n', 'e', 'm', 'o' };
    char NEMO[4] = { 'N', 'E', 'M', 'O' };
	char EOI[4] = "EOI";
    char buf[128];
    int ic, oc;
    
    while (true) {
        oc = 0;
        
        fgets(buf, 128, stdin);
		buf[strlen(buf) - 1] = '\0';
        
        if (!strcmp(buf, EOI)) {
            break;
        }
        
        for (int i = 0; buf[i + 3] != '\0'; ++i) {
            if (buf[i] == nemo[0] || buf[i] == NEMO[0]) {
                ic = 0;
                
                for (int j = 1; j < 4; ++j) {
                    if (buf[i + j] == nemo[j] || buf[i + j] == NEMO[j]) {
                        ++ic;
                    }
                    else {
                        break;
                    }
                }
                
                if (ic == 3) {
                    ++oc;
                    break;
                }
            }
        }
        
        puts((oc) ? "Found" : "Missing");
    }
    
    return 0;
}