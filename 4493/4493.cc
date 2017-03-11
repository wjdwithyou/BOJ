#include <iostream>

int main() {
    int t, n, wa, wb;
    char a, b;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        wa = wb = 0;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            while (getchar() != '\n');
            scanf("%c %c", &a, &b);
            
            switch (abs(b - a)) {
                case 1:
                    (a == 'R') ? ++wa : ++wb;
                    break;
                case 2:
                    (a == 'P') ? ++wa : ++wb;
                    break;
                case 3:
                    (a == 'S') ? ++wa : ++wb;
                    break;
                default:
                    break;
            }
        }
        
        if (wa == wb) {
            puts("TIE");
        } else {
            printf("Player %d\n", (wa > wb) ? 1 : 2);
        }
    }
    
    return 0;
}