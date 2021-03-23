#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}Node;

void add_node(Node **start, int value);
void print_list(Node *node);
//void inverse_print_list(Node *node);
void free_list(Node *node);
void deleteNode(Node **head_ref, Node* del);

int main(){
	int a;
	// create first node "head"
	Node *head = NULL;
	head -> data = -1;
	//store 15 random number array
	int randNum[15] = {0};
	//use time to get random value 
	srand(time(NULL));
	
	for (int i = 0; i < 15; i++){
		randNum[i] = a = (rand() % 1000) + 1;
	}
	
	add_node(&head, 5);
	add_node(&head, 128);
	add_node(&head, 41);

	print_list(head);
	
	Node *last = head;
	while(last->next->data != -1) {
		last = last->next;
	}
//	inverse_print_list(last);
	
	free_list(head);

	return 0;	
}

void add_node(Node **start, int value){
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	if(*start == NULL) {
		*start = new_node;
		return;
	}
	else {
		Node *current;	
		current = *start;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
		return;
	}
}

void print_list(Node *node){
	while(node != NULL) {
		printf("%d ", node->data); 
		node = node->next;
	}
	printf("\n");
}

//void inverse_print_list(Node *node){
//	while(node != NULL) {
//		printf("%d ", node->data); 
//		node = node->prev;
//	}
//	printf("\n");
//}

void free_list(Node *node){
	Node *current, *temp;
	current = node;
	while(current != NULL) {
		temp = current;
		current = current->next;
		free(temp);
	}
}

void deleteNode(Node** head_ref, Node* del){
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;
 
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}
