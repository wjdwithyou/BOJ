#include <iostream>
#include <cstring>

#define NUM_ALPHA 26

typedef struct Node {
    char* ptr;
    Node* next;
}Node;

Node* arr[32];

int main() {
    char buf[1024];
    Node* temp;
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        arr[i] = static_cast<Node*>(malloc(sizeof(Node)));
        arr[i]->next = NULL;
    }
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != NULL; ++i) {
        temp = static_cast<Node*>(malloc(sizeof(Node)));
        
        temp->ptr = &buf[i];
        
        for (Node* cur = arr[buf[i] - 'a'];; cur = cur->next) {
            if (cur->next == NULL || strcmp(cur->next->ptr, temp->ptr) > 0) {
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
        }
    }
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        while (arr[i]->next != NULL) {
            temp = arr[i]->next;
            
            puts(temp->ptr);
            
            arr[i]->next = temp->next;
            free(temp);
        }
        
        free(arr[i]);
    }
    
    return 0;
}