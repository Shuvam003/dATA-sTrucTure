#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node;
node* swap(node *ptr1, node *ptr2)
{
	node *tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}
int bubbleSort(node **head, int count)
{
	node **h;
	int i, j, swapped;
	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;
		for (j = 0; j < count - i - 1; j++) {
			node *p1 = *h;
			node *p2 = p1->next;
			if (p1->data > p2->data) {
				*h = swap(p1, p2);
				swapped = 1;
			}
			h = &(*h)->next;
		}
		if (swapped == 0)
			break;
	}
}
void printList(node *n)
{
	while (n != NULL) {
		printf("%d -> ", n->data);
		n = n->next;
	}
	printf("\n");
}
void insertAtTheBegin(node **start_ref, int data)
{
	node *ptr1 = (node*)malloc(sizeof(node));
	ptr1->data = data;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}
int main()
{
	int arr[] = { 78, 20, 10, 32, 1, 5 };
	int list_size, i;
	node *start = NULL;
	list_size = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < list_size; i++)
		insertAtTheBegin(&start, arr[i]);
	printf("Linked list before sorting\n");
	printList(start);
	bubbleSort(&start, list_size);
	printf("Linked list after sorting\n");
	printList(start);
	return 0;
}
