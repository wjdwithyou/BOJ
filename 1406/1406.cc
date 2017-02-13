#include <iostream>

typedef struct Node {
	char c;
	Node* prev;
	Node* next;
}Node;

char buf[131072];

int main() {
	char tbuf[8];
	Node *head, *cursor, *temp;
	int n;
	char command;

	head = static_cast<Node*>(malloc(sizeof(Node)));
	head->prev = head->next = head;

	scanf("%s", buf);

	for (int i = 0; buf[i] != '\0'; ++i) {
		Node* temp = static_cast<Node*>(malloc(sizeof(Node)));

		temp->c = buf[i];

		temp->prev = head->prev;
		head->prev = temp;
		temp->prev->next = temp;
		temp->next = head;
	}

	cursor = head->prev;

	scanf("%d", &n);

	while (getchar() != '\n');

	for (int i = 0; i < n; ++i) {
		fgets(tbuf, 8, stdin);

		switch (tbuf[0]) {
		case 'L':
			if (cursor != head) {
				cursor = cursor->prev;
			}
			break;
		case 'D':
			if (cursor->next != head) {
				cursor = cursor->next;
			}
			break;
		case 'B':
			if (cursor != head) {
				temp = cursor;

				cursor = cursor->prev;

				cursor->next = temp->next;
				temp->next->prev = cursor;
				free(temp);
			}
			break;
		case 'P':
			temp = static_cast<Node*>(malloc(sizeof(Node)));

			temp->c = tbuf[2];

			temp->next = cursor->next;
			cursor->next = temp;
			temp->next->prev = temp;
			temp->prev = cursor;

			cursor = temp;
			break;
		default:
			break;
		}
	}

	while (head->next != head) {
		temp = head->next;

		printf("%c", temp->c);

		head->next = temp->next;
		temp->next->prev = head;
		free(temp);
	}

	free(head);
	return 0;
}