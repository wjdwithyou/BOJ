#include <iostream>

typedef struct Student {
    int country;
    int num;
    int score;
}Student;

int main() {
    Student student[128];
    Student temp;
    int n, idx;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &student[i].country, &student[i].num, &student[i].score);
    }
    
    for (int i = 0; i < n; ++i) {
        idx = i;
        
        for (int j = i + 1; j < n; ++j) {
            if (student[idx].score < student[j].score) {
                idx = j;
            }
        }
        
        if (idx == i) {
            continue;
        }
        
        temp = student[i];
        student[i] = student[idx];
        student[idx] = temp;
    }
    
    if (student[0].country == student[1].country && student[1].country == student[2].country && student[2].country == student[0].country) {
        for (int i = 3; i < n; ++i) {
            if (student[2].country != student[i].country) {
                temp = student[2];
                student[2] = student[i];
                student[i] = temp;
                
                break;
            }
        }
    }
    
    for (int i = 0; i < 3; ++i) {
        printf("%d %d\n", student[i].country, student[i].num);
    }
    
    return 0;
}