#include <iostream>

int main() {
    int a1, a2, b1, b2;
    
    scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
    return !printf("%s", (a2 / b1 + (a2 % b1 != 0) == b2 / a1 + (b2 % a1 != 0)) ? "DRAW" : ((a2 / b1 + (a2 % b1 != 0) > b2 / a1 + (b2 % a1 != 0)) ? "PLAYER A" : "PLAYER B"));
}