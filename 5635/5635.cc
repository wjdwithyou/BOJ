#include <iostream>
#include <cstring>

typedef struct Person {
    char name[16];
    int date;
    int month;
    int year;
}Person;

int main() {
    Person young = { "", 0, 0, -1 };
    Person old = { "", 0, 0, 16384 };
    Person temp;
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", temp.name, &temp.date, &temp.month, &temp.year);
        
        if (young.year < temp.year || young.year == temp.year && young.month < temp.month || young.year == temp.year && young.month == temp.month && young.date < temp.date) {
            strcpy(young.name, temp.name);
            young.date = temp.date;
            young.month = temp.month;
            young.year = temp.year;
        }
        
        if (old.year > temp.year || old.year == temp.year && old.month > temp.month || old.year == temp.year && old.month == temp.month && old.date > temp.date) {
            strcpy(old.name, temp.name);
            old.date = temp.date;
            old.month = temp.month;
            old.year = temp.year;
        }
    }
    
    printf("%s\n%s", young.name, old.name);
    return 0;
}