#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node {
	int data;
	struct Node* next;
};

// Add new node at end of the list
void insert(struct Node** head, int value)
{
	// dynamic node
	struct Node* node
		= (struct Node*)malloc(sizeof(struct Node));
	if (node == NULL) {
		// checking overlow
		printf("Flag Memory overflow\n");
	}
	else {
		node->data = value;
		node->next = NULL;
		if (*head == NULL) {
			*head = node;
		}
		else {
			struct Node* temp = *head;

			// finding last node
			while (temp->next != NULL) {
				temp = temp->next;
			}

			// adding node at last position
			temp->next = node;
		}
	}
}

// Displaying linked list element
void display(struct Node* head)
{
	if (head == NULL) {
		printf("Empty linked list");
		return;
	}
	struct Node* temp = head;
	printf("\n Linked List :");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
}

// Finding last node of the list
struct Node* last_node(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}

// We are Setting the given last node position to its proper position

struct Node* parition(struct Node* first, struct Node* last)
{
	// Get first node 
	struct Node* pivot = first;
	struct Node* front = first;
	int temp = 0;
	while (front != NULL && front != last) {
		if (front->data < last->data) {
			pivot = first;

			// Switching node values
			temp = first->data;
			first->data = front->data;
			front->data = temp;

			// Going the next node
			first = first->next;
		}

		// Going the next node
		front = front->next;
	}

	// Change last node value to current node
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return pivot;
}

// Doing quick sort
void quick_sort(struct Node* first, struct Node* last)
{
	if (first == last) {
		return;
	}
	struct Node* pivot = parition(first, last);

	if (pivot != NULL && pivot->next != NULL) {
		quick_sort(pivot->next, last);
	}

	if (pivot != NULL && first != pivot) {
		quick_sort(first, pivot);
	}
}

// Driver's code
int main()
{
	struct Node* head = NULL;

	// Insert a linked-list
	insert(&head, 71);
	insert(&head, 51);
	insert(&head, 27);
	insert(&head, 28);
	insert(&head, 98);
	insert(&head, 61);
	insert(&head, 46);
	insert(&head, 18);
	insert(&head, 24);
	insert(&head, 91);
	printf("\n Before Sort ");
	display(head);

	// Function call
	quick_sort(head, last_node(head));
	printf("\n After Sort ");
	display(head);
	return 0;
}
