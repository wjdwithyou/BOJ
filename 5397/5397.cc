#include <iostream>

typedef struct Node {
    int c;
    Node* prev;
    Node* next;
}Node;

char buf[1048576];

int main() {
    Node *head, *cursor, *temp;
    int t;
    
    head = static_cast<Node*>(malloc(sizeof(Node)));
    head->prev = head->next = head;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        cursor = head;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            switch (buf[j]) {
                case '<':
                    if (cursor != head) {
                        cursor = cursor->prev;
                    }
                    break;
                case '>':
                    if (cursor->next != head) {
                        cursor = cursor->next;
                    }
                    break;
                case '-':
                    if (cursor != head) {
                        temp = cursor;
                        cursor = cursor->prev;
                        
                        cursor->next = temp->next;
                        temp->next->prev = cursor;
                        free(temp);
                    }
                    break;
                default:
                    temp = static_cast<Node*>(malloc(sizeof(Node)));
                    
                    temp->c = buf[j];
                    
                    temp->next = cursor->next;
                    cursor->next = temp;
                    temp->next->prev = temp;
                    temp->prev = cursor;
                    
                    cursor = temp;
                    
                    break;
            }
        }
        
        while (head->next != head) {
            temp = head->next;
            
            printf("%c", temp->c);
            
            head->next = temp->next;
            temp->next->prev = head;
            free(temp);
        }
        printf("\n");
    }
    
    free(head);
    return 0;
}