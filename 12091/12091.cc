#include <iostream>

int main() {
    char evo[4][16] = { "Vaporeon", "Jolteon", "Flareon" };
    int l;
    
    scanf("%d", &l);
    printf("%s", evo[((intptr_t)&l >> 4) % 3]);
    
	return 0;
}