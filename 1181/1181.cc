#include <iostream>
#include <cstring>

#define MAX_LEN 50

typedef struct Node {
    char word[64];
    Node* next;
}Node;

int main() {
    Node* word_arr[64];
    char buf[64];
    int n;
    
    for (int i = 1; i <= MAX_LEN; ++i) {
        word_arr[i] = static_cast<Node*>(malloc(sizeof(Node)));
        word_arr[i]->next = NULL;
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        
        for (Node* cur = word_arr[strlen(buf)];; cur = cur->next) {
            if (cur->next == NULL || strcmp(buf, cur->next->word) < 0) {
                Node* temp = static_cast<Node*>(malloc(sizeof(Node)));
                
                strcpy(temp->word, buf);
                
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
            else if (strcmp(buf, cur->next->word) == 0) {
                break;
            }
            else;
        }
    }
    
    for (int i = 1; i <= MAX_LEN; ++i) {
        Node* cur = word_arr[i];
        
        while (cur->next != NULL) {
            Node* temp = word_arr[i]->next;
            
            puts(temp->word);
            
            cur->next = temp->next;
            free(temp);
        }
        
        free(cur);
    }
    
    return 0;
}