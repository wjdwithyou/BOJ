#include <iostream>

int main() {
    char buf[4];
    float score = 0;
    
    scanf("%s", buf);
    
    switch (buf[0]) {
        case 'A':
            ++score;
        case 'B':
            ++score;
        case 'C':
            ++score;
        case 'D':
            ++score;
        default:
            break;
    }
    
    switch (buf[1]) {
        case '+':
            score += 0.3f;
            break;
        case '-':
            score -= 0.3f;
            break;
        default:
            break;
    }
    
    printf("%.1f", score);
    return 0;
}