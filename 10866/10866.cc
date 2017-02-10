#include <iostream>

typedef struct Node {
	int num;
	Node* prev;
	Node* next;
}Node;

int main() {
	char buf[32];
	Node *head, *tail;
	int n, x;
	int size = 0;

	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));

	head->next = tail;
	tail->prev = head;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);

		switch (buf[0]) {
		case 'p':
			if (buf[1] == 'u') {
				Node* temp = (Node*)malloc(sizeof(Node));

				scanf("%d", &x);

				temp->num = x;

				if (buf[5] == 'f') {
					temp->next = head->next;
					head->next = temp;
					temp->next->prev = temp;
					temp->prev = head;
				}
				else {
					temp->prev = tail->prev;
					tail->prev = temp;
					temp->prev->next = temp;
					temp->next = tail;
				}

				++size;
			}
			else {
				if (size == 0) {
					puts("-1");
				}
				else {
					Node* temp;

					if (buf[4] == 'f') {
						temp = head->next;

						head->next = temp->next;
						temp->next->prev = head;
					}
					else {
						temp = tail->prev;

						tail->prev = temp->prev;
						temp->prev->next = tail;
					}

					printf("%d\n", temp->num);
					free(temp);

					--size;
				}
			}
			break;
		case 's':
			printf("%d\n", size);
			break;
		case 'e':
			printf("%d\n", (size) ? 0 : 1);
			break;
		case 'f':
			printf("%d\n", (size) ? head->next->num : -1);
			break;
		case 'b':
			printf("%d\n", (size) ? tail->prev->num : -1);
			break;
		default:
			break;
		}
	}

	while (head->next != tail) {
		Node* temp = head->next;

		head->next = temp->next;
		temp->next->prev = head;

		free(temp);
	}

	free(tail);
	free(head);

	return 0;
}