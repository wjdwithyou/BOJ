#include <iostream>

int main() {
    char name[1024];
    int age, weight;
    
    while (true) {
        scanf("%s %d %d", name, &age, &weight);
        
        if (!age || !weight) {
            break;
        }
        
        printf("%s %s\n", name, (age < 18 && weight < 80) ? "Junior" : "Senior");
    }
    
    return 0;
}