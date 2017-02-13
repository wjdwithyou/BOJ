#include <iostream>

typedef struct Node {
    int num;
    int move;
    Node* prev;
    Node* next;
}Node;

int main() {
    Node *head, *cursor, *temp;
    int n;
    
    head = static_cast<Node*>(malloc(sizeof(Node)));
    head->prev = head->next = head;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        temp = static_cast<Node*>(malloc(sizeof(Node)));
        
        temp->num = i;
        scanf("%d", &temp->move);
        
        temp->prev = head->prev;
        head->prev = temp;
        temp->prev->next = temp;
        temp->next = head;
    }
    
    cursor = head->next;
    
    cursor->prev = head->prev;
    head->prev->next = cursor;
    free(head);
    
    for (int i = 0; i < n; ++i) {
        temp = cursor;
        
        printf("%d ", cursor->num);
        
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
        
        if (cursor->move < 0) {
            for (int j = 0; j > cursor->move; --j) {
                temp = temp->prev;
            }
        }
        else {
            for (int j = 0; j < cursor->move; ++j) {
                temp = temp->next;
            }
        }
        
        free(cursor);
        cursor = temp;
    }
    
    return 0;
}