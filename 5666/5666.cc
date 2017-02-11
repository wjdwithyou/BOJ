#include <iostream>

int main() {
    int h, p;
    
    while (fscanf(stdin, "%d %d", &h, &p) != EOF) {
        printf("%.2f\n", static_cast<double>(h) / p);
    }
    
    return 0;
}