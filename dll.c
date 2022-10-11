#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t* front = (node_t*) malloc(sizeof(node_t));
	front->data = data;
	if(list->head == NULL){
		front->next = NULL;
		front->prev = NULL;
		list->head = front;
		list->tail = front;
		list->size += 1;
	}
	else{
		front->prev = NULL;
		front->next = list->head;
		list->head->prev = front;
		list->head = front;
		list->size += 1;
	}
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t* rear = (node_t*) malloc(sizeof(node_t));
	rear->data = data;
	if(list->tail == NULL){
		rear->prev = NULL;
		rear->next = NULL;
		list->tail = rear;
		list->head = rear;
		list->size += 1;
	}
	else{
		rear->prev = list->tail;
		rear->next = NULL;
		list->tail->next = rear;
		list->tail = rear;
		list->size += 1;
	}
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* curr = list->head;
	node_t* insert = (node_t*) malloc(sizeof(node_t));
	insert->data = data;
	while(curr != NULL){
		if(curr->data == prev){
			if(curr == list->tail){
				insert_back(list, data);
			}
			else{
				curr->next->prev = insert;
				insert->next = curr->next;
				curr->next = insert;
				insert->prev = curr;
				list->size += 1;
				return;
			}
		}
		else{
			curr = curr->next;
		}
	}
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	node_t* front = list->head;
	if(front->next == NULL){
		free(front);
		list->size -= 1;
	}
	else{
		list->head = front->next;
		front->next->prev = NULL;
		free(front);
		list->size -= 1;
	}
	
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	node_t* rear = list->tail;
	if(rear->prev == NULL){
		free(rear);
		list->size -= 1;
	}
	else{
		list->tail = rear->prev;
		rear->prev->next = NULL;
		free(rear);
		list->size -= 1;
	}
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t* curr = list->head;
	while(curr != NULL){
		if(curr->data == data){
			if(curr == list->head){
				delete_front(list);
				return;
			}
			else if(curr == list->tail){
				delete_back(list);
				return;
			}
			else{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				free(curr);
				list->size -= 1;
				return;
			}
		}
		else{
			curr = curr->next;
		}
	}
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
	node_t* curr = list->head;
	int i = 1;
	while(curr != NULL){
		if(curr->data = data){
			return curr;
		}
		else{
			curr = curr->next;
			i += 1;
		}
	}
	if(i > list->size){
		return NULL;
	}
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

// int main()
// {
// 	int ch;
// 	int input;
// 	int prev;
// 	list_t* mylist;
// 	while(1){
// 		printf("1 to create list, 2 to insert start, 3 to insert end, 4 to insert after, 5 delete front, 6 delete back\n7 to delete node, 8 to search, 9 size, 10 delete nodes, 11 delete list, 12 display list:");
// 		scanf("%d", &ch);
// 		switch(ch){
// 			case 1: 
// 				mylist = create_list();
// 				break;
// 			case 2:
// 				scanf("%d", &input);
// 				insert_front(mylist, input);
// 				break;
// 			case 3:
// 				scanf("%d", &input);
// 				insert_back(mylist, input);
// 				break;
// 			case 4:
// 				printf("input and stored data:");
// 				scanf("%d%d", &input, &prev);
// 				insert_after(mylist, input, prev);
// 				break;
// 			case 5:
// 				delete_front(mylist);
// 				break;
// 			case 6:
// 				delete_back(mylist);
// 				break;
// 			case 7:
// 				scanf("%d", &input);
// 				delete_node(mylist, input);
// 				break;
// 			case 8:
// 				scanf("%d", &input);
// 				node_t* new = search(mylist, input);
// 				printf("%d", new->data);
// 				break;
// 			case 9:
// 				printf("%d", size(mylist));
// 				break;
// 			case 10:
// 				delete_nodes(mylist->head);
// 				break;
// 			case 11:
// 				delete_list(mylist);
// 				break;
// 			case 12:
// 				display_list(mylist);
// 				break;
// 		}
// 	}
// }
