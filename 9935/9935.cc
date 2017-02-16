#include <iostream>

typedef struct Node {
    char c;
    Node* prev;
    Node* next;
    Node* bprev;
    Node* bnext;
}Node;

char buf[1048576];

int main() {
    char burst[64];
    Node *head, *temp;
    
    head = static_cast<Node*>(malloc(sizeof(Node)));
    head->prev = head->next = head->bprev = head->bnext = head;
    
    scanf("%s", buf);
    scanf("%s", burst);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        temp = static_cast<Node*>(malloc(sizeof(Node)));
        
        temp->c = buf[i];
        
        temp->prev = head->prev;
        head->prev = temp;
        temp->prev->next = temp;
        temp->next = head;
        
        if (temp->c == burst[0]) {
            temp->bprev = head->bprev;
            head->bprev = temp;
            temp->bprev->bnext = temp;
            temp->bnext = head;
        }
    }
    
    Node* ccur;
    int outer, inner;
    
    do {
        outer = 0;
        
        for (Node* cur = head->bnext; cur != head;) {
            ccur = cur;
            inner = 1;
            
            for (int i = 0; burst[i] != '\0'; ++i, ccur = ccur->next) {
                if (ccur->c != burst[i]) {
                    --inner;
                    break;
                }
            }
            
            if (inner) {
                temp = cur;
                cur = cur->bprev;
                
                cur->bnext = temp->bnext;
                temp->bnext->bprev = cur;
                
                temp = temp->prev;
                
                while (temp->next != ccur) {
                    temp->next = temp->next->next;
                    free(temp->next->prev);
                    temp->next->prev = temp;
                }
                
                ++outer;
            }
            else {
                cur = cur->bnext;
            }
        }
    } while (outer);
    
    if (head->next == head) {
        printf("FRULA");
    }
    else {
        while (head->next != head) {
            temp = head->next;
            
            printf("%c", temp->c);
            
            head->next = temp->next;
            temp->next->prev = head;
            
            if (temp->c == burst[0]) {
                head->bnext = temp->bnext;
                temp->bnext->bprev = head;
            }
            
            free(temp);
        }
    }
    
    free(head);
    return 0;
}