#include <iostream>

int main() {
    int aaa, bbb, ccc, ddd;
    
    for (int a = 2; a <= 100; ++a) {
        aaa = a * a * a;
        
        for (int b = 2;; ++b) {
            bbb = b * b * b;
            
            if (aaa <= bbb) {
                break;
            }
            
            for (int c = b;; ++c) {
                ccc = c * c * c;
                
                if (aaa <= bbb + ccc) {
                    break;
                }
                
                for (int d = c;; ++d) {
                    ddd = d * d * d;
                    
                    if (aaa == bbb + ccc + ddd) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                        break;
                    } else if (aaa < bbb + ccc + ddd) {
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}