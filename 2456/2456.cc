#include <iostream>

struct Person {
    int cnt[4];
    int num;
    int sum;
};

int _print(Person*[], int);

int main() {
    Person* person[4];
    int n, t, idx;
    
    for (int i = 1; i < 4; ++i) {
        person[i] = static_cast<Person*>(malloc(sizeof(Person)));
        
        for (int j = 1; j < 4; ++j) {
            person[i]->cnt[j] = 0;
        }
        
        person[i]->num = i;
        person[i]->sum = 0;
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 4; ++j) {
            scanf("%d", &t);
            
            person[j]->sum += t;
            ++person[j]->cnt[t];
        }
    }
    
    for (int i = 1; i < 4; ++i) {
        idx = i;
        
        for (int j = i + 1; j < 4; ++j) {
            if (person[idx]->sum > person[j]->sum);
            else if (person[idx]->sum == person[j]->sum && person[idx]->cnt[3] > person[j]->cnt[3]);
            else if (person[idx]->sum == person[j]->sum && person[idx]->cnt[3] == person[j]->cnt[3] && person[idx]->cnt[2] > person[j]->cnt[2]);
            else {
                idx = j;
            }
        }
        
        if (idx == i) {
            continue;
        }
        
        person[0] = person[i];
        person[i] = person[idx];
        person[idx] = person[0];
    }
    
    if (person[1]->sum > person[2]->sum);
    else if (person[1]->sum == person[2]->sum && person[1]->cnt[3] > person[2]->cnt[3]);
    else if (person[1]->sum == person[2]->sum && person[1]->cnt[3] == person[2]->cnt[3] && person[1]->cnt[2] > person[2]->cnt[2]);
    else {
        return _print(person, 0);
    }
    
    return _print(person, person[1]->num);
}

int _print(Person* person[], int num) {
    printf("%d %d", num, person[1]->sum);
    
    for (int i = 1; i < 4; ++i) {
        free(person[i]);
    }
    
    return 0;
}