#include <iostream>
#include <cstring>

#define NUM_ALPHA 26

typedef struct Node {
    char num[32];
    int no;
    Node* next;
}Node;

int main() {
    char eng[16][8] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    char buf[4];
    Node* list[32];
    Node* temp;
    int m, n;
    int cnt = 0;
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        list[i] = static_cast<Node*>(malloc(sizeof(Node)));
        list[i]->next = NULL;
    }
    
    scanf("%d %d", &m, &n);
    
    for (int i = m; i <= n; ++i) {
        temp = static_cast<Node*>(malloc(sizeof(Node)));
        
        memset(temp->num, 0, sizeof(temp->num));
        
        sprintf(buf, "%d", i);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            strcat(temp->num, eng[buf[j] - '0']);
            strcat(temp->num, " ");
        }
        
        temp->num[strlen(temp->num) - 1] = '\0';
        
        temp->no = i;
        
        for (Node* cur = list[temp->num[0] - 'a'];; cur = cur->next) {
            if (cur->next == NULL || strcmp(cur->next->num, temp->num) > 0) {
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
        }
    }
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        while (list[i]->next) {
            temp = list[i]->next;
            
            printf("%d ", temp->no);
            
            if (++cnt >= 10) {
                cnt = 0;
                printf("\n");
            }
            
            list[i]->next = temp->next;
            free(temp);
        }
        
        free(list[i]);
    }
    
    return 0;
}