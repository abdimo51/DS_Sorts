
// C program for linked list arithmetic..
#include <stdio.h>
#include <stdlib.h>

// Nodes
typedef struct Node {
	int data;
	struct Node* next;
}Node;

// Function for new node with provided data

Node* newNode(int data)
{
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// inserts a node at the beginning of the linked list
void push(Node** head_ref, int new_data)
{
	// allocates nodes
	Node* new_node = newNode(new_data);
// links the old list to the new node
	new_node->next = (*head_ref);
	// match the head and the new node
	(*head_ref) = new_node;
}

/* Adds elements of linked lists and returns the head node of resultant list */
Node* add_lists(Node* first, Node* second)
{
	// is the head node of the resultant list
	Node* res = NULL;
	Node *temp, *prev = NULL;
	int carry = 0, sum;


	while (first != NULL || second != NULL) {
		
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
		// updates carry for following operation
		carry = (sum >= 10) ? 1 : 0;
		// updates sum if > 10
		sum = sum % 10;
		// Creates a new node with sum being the data
		temp = newNode(sum);
		// If first node then make it as head of the resultant
		if (res == NULL)
			res = temp;
		// If not the first node then link it to the rest.
		else
			prev->next = temp;
	
		prev = temp;

		// Replace next nodes as the first and second pointers
		
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}
	if (carry > 0)
		temp->next = newNode(carry);
	// returns the head of the resultant list
	return res;
}

Node* reverse(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	/* reverses the rest list and positions the first element at the end */
	Node* rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	// fixes the head pointer in case needed
	return rest;
}

// Prints a linked list
void print_list(Node* node)
{
	while (node != NULL) {
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
}

/* Test Code */
int main(void)
{
	Node* res = NULL;
	Node* first = NULL;
	Node* second = NULL;

	// First list 8->4->10->3->7
	push(&first, 7);
	push(&first, 3);
	push(&first, 10);
	push(&first, 4);
	push(&first, 8);
	push(&first, 7);
	push(&first, 3);
	push(&first, 10);
	push(&first, 4);
	push(&first, 8);
	push(&first, 7);
	push(&first, 3);
	push(&first, 10);
	push(&first, 4);
	push(&first, 8);
	push(&first, 7);
	push(&first, 3);
	push(&first, 10);
	push(&first, 4);
	push(&first, 8);
	printf("1st List: ");
	print_list(first);

	//Second list 6->8->7->3->6->9->5->6->8->7->3->6->9->5
	push(&second, 5);
	push(&second, 9);
	push(&second, 6);
	push(&second, 3);
	push(&second, 7);
	push(&second, 8);
	push(&second, 6);
	push(&second, 5);
	push(&second, 9);
	push(&second, 6);
	push(&second, 3);
	push(&second, 7);
	push(&second, 8);
	push(&second, 6);
	printf("2nd list: ");
	print_list(second);

	// reverses 1st and 2nd list
	first = reverse(first);
	second = reverse(second);
	// Adds the lists
	res = add_lists(first, second);

	// reverses the resultant to obtain the sum
	res = reverse(res);
	printf("Resultant list: ");
	print_list(res);
	return 0;
}

// citation: https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-list/