#include <iostream>
#include <cstring>

typedef struct Song {
    char title[32];
    int lowest;
}Song;

typedef struct Node {
    Song song;
    Node* next;
}Node;

Song song[512];
int counter[512];

int main() {
    char buf[32];
    Node *head, *temp;
    int n, a, b, sdx;
    int idx = 1, tsum = 0;
    
    head = static_cast<Node*>(malloc(sizeof(Node)));
    head->next = NULL;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d od %d ", &a, &b);
        
        for (int j = 0; j < a; ++j) {
            sdx = 1;
            
            scanf("%s", buf);
            
            for (; sdx < idx; ++sdx) {
                if (!strcmp(song[sdx].title, buf)) {
                    break;
                }
            }
            
            if (sdx == idx) {
                strcpy(song[sdx].title, buf);
                song[sdx].lowest = b;
                ++counter[b];
                ++idx;
            }
            else {
                if (b < song[sdx].lowest) {
                    --counter[song[sdx].lowest];
                    song[sdx].lowest = b;
                    ++counter[song[sdx].lowest];
                }
            }
        }
    }
    
    for (int i = 1; i < idx; ++i) {
        tsum += counter[i];
        
        if (counter[i] == 1 && tsum == i) {
            int j = 1;
            
            for (; j < idx; ++j) {
                if (i == song[j].lowest) {
                    break;
                }
            }
            
            temp = static_cast<Node*>(malloc(sizeof(Node)));
            
            strcpy(temp->song.title, song[j].title);
            temp->song.lowest = song[j].lowest;
            
            for (Node* cur = head;; cur = cur->next) {
                if (cur->next == NULL || temp->song.lowest < cur->next->song.lowest) {
                    temp->next = cur->next;
                    cur->next = temp;
                    break;
                }
            }
        }
    }
    
    while (head->next != NULL) {
        temp = head->next;
        
        printf("%d %s\n", temp->song.lowest, temp->song.title);
        
        head->next = temp->next;
        free(temp);
    }
    
    free(head);
    return 0;
}