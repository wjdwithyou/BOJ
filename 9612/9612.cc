#include <iostream>
#include <cstring>

typedef struct Node {
    char word[32];
    int cnt;
    Node* next;
}Node;

int main() {
    char buf[32];
    Node *head, *temp;
    int n;
    
    head = static_cast<Node*>(malloc(sizeof(Node)));
    head->next = NULL;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        
        for (Node* cur = head;; cur = cur->next) {
            if (!cur->next || strcmp(cur->next->word, buf) > 0) {
                temp = static_cast<Node*>(malloc(sizeof(Node)));
                
                strcpy(temp->word, buf);
                temp->cnt = 1;
                
                temp->next = cur->next;
                cur->next = temp;
                
                break;
            } else if (!strcmp(cur->next->word, buf)) {
                ++cur->next->cnt;
                break;
            } else;
        }
    }
    
    n = 0;
    
    while (temp = head->next) {
        if (n <= temp->cnt) {
            strcpy(buf, temp->word);
            n = temp->cnt;
        }
        
        head->next = temp->next;
        free(temp);
    }
    
    free(head);
    
    printf("%s %d", buf, n);
    return 0;
}