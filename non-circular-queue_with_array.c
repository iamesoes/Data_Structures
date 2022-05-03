#include<stdio.h>
#include<stdlib.h>
#define MAX 19
typedef struct queue{
	int front;
	int rear;
	int array[MAX];
}QUEUE; //we will use QUEUE shortcut to create this struct

void enqueue(QUEUE *q, int value){
	if(q->rear==MAX-1){
		printf("The queue is full.\n");
		return; //no more process
	}
	if(q->front==-1){
		q->front =0; //initialize the queue 
	}
	q->rear++; //arranging the rear 
	q->array[q->rear]=value; //we add the value to rear
	printf("%d is added to the queue.\n",value);
}

void dequeue(QUEUE *q){
	if(q->front==-1){
		printf("The queue is empty.\n");
		return;
	}
	printf("%d is removed from the queue.\n",q->array[q->front]);
	q->front++; //we remove at the front
	//there is still that value there however we cannot reach now by increasing the index of front
	if(q->front > q->rear){ //it means we ended up the array so we can restart it
		q->front = q->rear=-1;
	}
}

void printQueue(QUEUE *q){
	if(q->front==-1){
		printf("The queue is empty.\n");
		return;
	}
	int i;
	printf("**QUEUE**\n");
	for(i=(q->front);i<=(q->rear);i++){
		printf("%d ",q->array[i]);
	}
	printf("\n");
}

int main(){

	QUEUE *myqueue = (QUEUE*)malloc(sizeof(QUEUE));
	if(myqueue == NULL){
		printf("Allocation Error!\n");
		exit(1);
	}
	myqueue->front = myqueue->rear = -1; //initialize
	enqueue(myqueue,15);
	enqueue(myqueue,9);
	enqueue(myqueue,21);
	printQueue(myqueue);
	dequeue(myqueue);
	printQueue(myqueue);
	dequeue(myqueue);
	printQueue(myqueue);
	dequeue(myqueue);
	printQueue(myqueue);

	
	
	return 0;
}


