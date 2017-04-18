#include <iostream>

typedef struct Node {
    char c;
    Node* next;
}Node;

void insertNode(Node*, char);
void insertNode(Node*, Node*);
void moveToFront(Node*, Node*);
void releaseList(Node*);

int main() {
    Node* head = static_cast<Node*>(malloc(sizeof(Node)));
    int t, n, a, k;
    
    head->next = NULL;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        for (char c = 'z'; c >= 'a'; --c) {
            insertNode(head, c);
        }
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            k = 0;
            
            scanf("%d", &a);
            
            for (Node* cur = head; k < 26; cur = cur->next, ++k) {
                if (a == k) {
                    moveToFront(head, cur);
                    break;
                }
            }
        }
        
        puts("");
        releaseList(head);
    }
    
    return 0;
}

void insertNode(Node* head, char c) {
    Node* temp = static_cast<Node*>(malloc(sizeof(Node)));
    
    temp->c = c;
    
    insertNode(head, temp);
    
    return;
}

void insertNode(Node* head, Node* temp) {
    temp->next = head->next;
    head->next = temp;
    
    return;
}

void moveToFront(Node* head, Node* cur) {
    Node* temp = cur->next;
    
    printf("%c", temp->c);
    
    cur->next = temp->next;
    
    insertNode(head, temp);
    
    return;
}

void releaseList(Node* head) {
    Node* temp;
    
    while (head->next) {
        temp = head->next;
        
        head->next = temp->next;
        free(temp);
    }
    
    return;
}