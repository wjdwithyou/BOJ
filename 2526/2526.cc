#include <iostream>

typedef struct Node {
    int chk;
    Node* next;
}Node;

int main() {
    Node* arr[128];
    Node *head, *last;
    int n, p, t;
    int s = 0;
    
    head = static_cast<Node*>(malloc(sizeof(Node)));
    last = head;
    
    scanf("%d %d", &n, &p);
    
    for (int i = 0; i < p; ++i) {
        arr[i] = static_cast<Node*>(malloc(sizeof(Node)));
        arr[i]->chk = 0;
        arr[i]->next = NULL;
    }
    
    t = n;
    
    do {
        t = (t * n) % p;
        
        last->next = arr[t];
        last = arr[t];
    } while (last->next == NULL);
    
    for (Node* cur = last; !cur->chk; cur = cur->next) {
        ++cur->chk;
    }
    
    for (int i = 0; i < p; ++i) {
        s += arr[i]->chk;
        free(arr[i]);
    }
    
    free(head);
    
    printf("%d", s);
    return 0;
}