#include <stdio.h>
#include <stdlib.h>

//Node struct for the Linked List
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

//An empty list is created.
void create_list(struct Node **head_ref) {
	*head_ref = NULL;
	printf("List created successfully.");
	return;
}

/* Given reference to the head of the list, this function
inserts a node at the beginning of the List*/
void insert(struct Node **head_ref, int new_data) {
	//Allocate memory for the node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

/*Given reference to the head of the list, insert_before()
adds a node before a given node*/
void insert_before(struct Node *next_node, int new_data) {
	if (next_node == NULL) {
		printf("The given Next node is NULL");
		return;
	}
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->prev = next_node->prev;
	next_node->prev = new_node;
	new_node->next = next_node;
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
}

// Print the list in both directions
void print_list(struct Node *node) {
	struct Node* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		last = last->prev;
	}
	printf("\n");
}

int main() {
	struct Node *head;
	create_list(&head);
	insert(&head, 7);
	insert(&head, 1);
	insert(&head, 4);
	insert_before(head->next, 8);
	print_list(head);
	return 0;
}
