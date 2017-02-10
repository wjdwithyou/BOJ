#include <iostream>
#include <cstring>

#define MAX_AGE 200

typedef struct Node {
    char name[128];
    Node* prev;
    Node* next;
}Node;

int main() {
    Node* member[256];
    char buf[128];
    int n, a;
    
    for (int i = 1; i <= MAX_AGE; ++i) {
        member[i] = (Node*)malloc(sizeof(Node));
        member[i]->prev = member[i]->next = member[i];
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        Node* temp = (Node*)malloc(sizeof(Node));
        
        scanf("%d %s", &a, buf);
        
        strcpy(temp->name, buf);
        
        temp->prev = member[a]->prev;
        member[a]->prev = temp;
        temp->prev->next = temp;
        temp->next = member[a];
    }
    
    for (int i = 1; i <= MAX_AGE; ++i) {
        while (member[i]->next != member[i]) {
            Node* cur = member[i]->next;
            
            printf("%d %s\n", i, cur->name);
            
            member[i]->next = cur->next;
            cur->next->prev = member[i];
            free(cur);
        }
        
        free(member[i]);
    }
    
    return 0;
}