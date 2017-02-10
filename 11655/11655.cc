#include <iostream>

void ROT13(char*);
bool isUpper(char);
bool isLower(char);

int main() {
    char buf[128];
    
    fgets(buf, 128, stdin);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        ROT13(&buf[i]);
    }
    
    printf("%s", buf);
    return 0;
}

void ROT13(char* c) {
    if (isUpper(*c) || isLower(*c)) {
        *c += (*c <= ((isUpper(*c)) ? 'M' : 'm')) ? 13 : -13;
    }
    
    return;
}

bool isUpper(char c) {
    return (c >= 'A' && c <= 'Z') ? true: false;
}

bool isLower(char c) {
    return (c >= 'a' && c <= 'z') ? true: false;
}