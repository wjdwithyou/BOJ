#include <iostream>
#include <cstring>

#define MAX_LEN 50

typedef struct Node {
    char serial[64];
    int sum;
    Node* next;
}Node;

Node* arr[64];

int main() {
    int n;
    Node* temp;
    
    for (int i = 1; i <= MAX_LEN; ++i) {
        arr[i] = static_cast<Node*>(malloc(sizeof(Node)));
        arr[i]->next = NULL;
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        temp = static_cast<Node*>(malloc(sizeof(Node)));
        
        scanf("%s", temp->serial);
        temp->sum = 0;
        
        for (int j = 0; temp->serial[j] != '\0'; ++j) {
            if (temp->serial[j] >= '0' && temp->serial[j] <= '9') {
                temp->sum += temp->serial[j] - '0';
            }
        }
        
        for (Node* cur = arr[strlen(temp->serial)];; cur = cur->next) {
            if (cur->next == NULL || cur->next->sum > temp->sum || cur->next->sum == temp->sum && strcmp(cur->next->serial, temp->serial) > 0) {
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
        }
    }
    
    for (int i = 1; i <= MAX_LEN; ++i) {
        while (temp = arr[i]->next) {
            puts(temp->serial);
            
            arr[i]->next = temp->next;
            free(temp);
        }
        
        free(arr[i]);
    }
    
    return 0;
}