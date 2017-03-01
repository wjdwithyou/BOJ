#include <iostream>

typedef struct Person {
    int weight;
    int height;
    int rank;
}Person;

int main() {
    Person person[64];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &person[i].weight, &person[i].height);
        
        person[i].rank = 1;
        
        for (int j = 0; j < i; ++j) {
            if (person[j].weight < person[i].weight && person[j].height < person[i].height) {
                ++person[j].rank;
            } else if (person[j].weight > person[i].weight && person[j].height > person[i].height) {
                ++person[i].rank;
            } else;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%d ", person[i].rank);
    }
    
    return 0;
}