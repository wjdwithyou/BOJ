#include <iostream>

#define MAX_NUM 100000

typedef struct Node {
    int x;
    Node* next;
}Node;

Node* arr[262144];

int main() {
    int n, x, y;
    
    for (int i = 0; i <= 2 * MAX_NUM; ++i) {
        arr[i] = static_cast<Node*>(malloc(sizeof(Node)));
        arr[i]->next = NULL;
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        
        for (Node* cur = arr[y + MAX_NUM];; cur = cur->next) {
            if (cur->next == NULL || cur->next->x > x) {
                Node* temp = static_cast<Node*>(malloc(sizeof(Node)));
                
                temp->x = x;
                
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
        }
    }
    
    for (int i = 0; i <= 2 * MAX_NUM; ++i) {
        while (arr[i]->next != NULL) {
            Node* temp = arr[i]->next;
            
            printf("%d %d\n", temp->x, i - MAX_NUM);
            
            arr[i]->next = temp->next;
            free(temp);
        }
        
        free(arr[i]);
    }
    
    return 0;
}