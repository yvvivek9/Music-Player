#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t* create_queue()   // return a newly created empty queue
{
	// DO NOT MODIFY!!!
	queue_t* Q = (queue_t*) malloc(sizeof(queue_t));
	Q->list = create_list();
	Q->front = Q->list->head;
	Q->rear = Q->list->tail;
	Q->size = Q->list->size;
	return Q;
}

void enqueue(queue_t* q, int data) // TODO: insert data at the end of a queue
{
	insert_back(q->list, data);
	q->front = q->list->head;
	q->rear = q->list->tail;
	q->size += 1;
}

int dequeue(queue_t* q) 	// TODO: return the data at the front of a queue and remove it. Return -1 if queue is empty
{
	int i = q->front->data;
	delete_front(q->list);
	q->front = q->list->head;
	q->rear = q->list->tail;
	q->size -= 1;
	return i;
}

int front(queue_t* q) // TODO: return the data at the front of a queue. Return -1 if queue is empty
{
	if(q->size == 0){
		return -1;
	}
	else{
		return q->front->data;
	}
}

int empty(queue_t* q) // return if the queue is empty
{
	// DO NOT MODIFY!!!
	return is_empty(q->list);
}

int queue_size(queue_t* q) // returns the number of elements in the queue
{
	// DO NOT MODIFY!!!
	return q->size;
}

void delete_queue(queue_t* q) // empty the contents of the queue
{
	// DO NOT MODIFY!!!
	delete_list(q->list);
	free(q);
}

// int main()
// {
// 	int ch;
// 	int input;
// 	queue_t* myq;
// 	while(1){
// 		printf("1 create, 2 enque, 3 deque, 4 display front:");
// 		scanf("%d", &ch);
// 		switch(ch){
// 			case 1:
// 				myq = create_queue();
// 				break;
// 			case 2:
// 				scanf("%d", &input);
// 				enqueue(myq, input);
// 				break;
// 			case 3:
// 				printf("%d", dequeue(myq));
// 				break;
// 			case 4:
// 				printf("%d", front(myq));
// 				break;
// 		}
// 	}
// }


