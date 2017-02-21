#include <iostream>

int main() {
    int n, x, y, q1, q2, q3, q4, axis;
    
    q1 = q2 = q3 = q4 = axis = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        (x == 0 || y == 0) ? ++axis : ((y > 0) ? ((x > 0) ? ++q1 : ++q2) : ((x < 0) ? ++q3 : ++q4));
    }
    
    printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d\n", q1, q2, q3, q4, axis);
    return 0;
}