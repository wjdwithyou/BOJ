#include <iostream>

typedef struct Node {
    int adj;
    int len;
    int chk;
    Node* next;
}Node;

Node* intersection[131072];

void getFar(int, int, int*);

int main() {
    int n, s, a, b, c;
    int sum = 0, max = 0;
    
    scanf("%d %d", &n, &s);
    
    for (int i = 1; i <= n; ++i) {
        intersection[i] = static_cast<Node*>(malloc(sizeof(Node)));
        intersection[i]->chk = 0;
        intersection[i]->next = NULL;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        Node* temp1 = static_cast<Node*>(malloc(sizeof(Node)));
        Node* temp2 = static_cast<Node*>(malloc(sizeof(Node)));
        
        scanf("%d %d %d", &a, &b, &c);
        
        temp1->adj = b;
        temp2->adj = a;
        temp1->len = temp2->len = c;
        
        temp1->next = intersection[a]->next;
        intersection[a]->next = temp1;
        
        temp2->next = intersection[b]->next;
        intersection[b]->next = temp2;
        
        sum += c;
    }
    
    getFar(s, 0, &max);
    printf("%d", 2 * sum - max);
    
    for (int i = 1; i <= n; ++i) {
        while (intersection[i]->next != NULL) {
            Node* temp = intersection[i]->next;
            
            intersection[i]->next = temp->next;
            free(temp);
        }
        
        free(intersection[i]);
    }
    
    return 0;
}

void getFar(int idx, int len, int* max) {
    int chk = 0;
    
    ++intersection[idx]->chk;
    
    for (Node* cur = intersection[idx]->next; cur != NULL; cur = cur->next) {
        if (!intersection[cur->adj]->chk) {
            ++chk;
            getFar(cur->adj, len + cur->len, max);
        }
    }
    
    if (!chk && len > *max) {
        *max = len;
    }
    
    return;
}