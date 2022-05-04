#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct queue{
	int front;
	int rear;
	int array[MAX];
}QUEUE; //we will use QUEUE shortcut to create this struct


void enqueue(QUEUE *q,int value){
	if((q->front==0 && q->rear==MAX-1) || ((q->rear)+1==q->front) ){
		printf("The queue is full. %d could not added.\n",value);
		return; //no more process
	}
	
	if(q->front==-1){ //if it is empty
		q->front=0; //initialize front. We will increase rear index outside of this if
	}
	else if(q->rear==MAX-1){ //if we are about to turn to front
		q->rear=-1; //we simply initialize. We will increase rear index outside of this if
	}
	q->rear++;
	q->array[q->rear]=value;
	printf("%d is added to the queue.\n",value);
}

void dequeue(QUEUE *q){
	if(q->front==-1){
		printf("The queue is empty.\n");
		return; 
	}
	printf("%d is removing from the queue...",q->array[q->front]);
	if(q->front==q->rear){ //there is only one item
		q->front=q->rear=-1; //make it empty
		return;
	}
	if(q->front==MAX-1){ //we keep dequeue from circular structure (index of 0)
		q->front=0;
	}
	else{
		q->front++; //for other cases we just move the front 
	}
	printf("Done.\n");
	
}

void printQueue(QUEUE *q){
	if(q->front==-1){
		printf("The queue is empty.\n");
		return;
	}
	int i;
	printf("**CIRCULAR QUEUE**\n");
	if(q->rear > q->front){
		for(i=q->front;i<=q->rear;i++){
			printf("%d ",q->array[i]);
		}
	}
	else if(q->rear==q->front){ //if there is one item
		printf("%d ",q->array[q->front]);
	}
	else{
		for(i=q->front;i<MAX;i++){//firsly we display front to end of the array
			printf("%d ",q->array[i]);
		}
		for(i=0;i<=q->rear;i++){ //we keep display from at the beginning of the array to rear
			printf("%d ",q->array[i]);
		}
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
	enqueue(myqueue,3);
	printQueue(myqueue);
	enqueue(myqueue,7);
	printQueue(myqueue);
	dequeue(myqueue);
	printQueue(myqueue);
	enqueue(myqueue,19);
	printQueue(myqueue);
	dequeue(myqueue);
	printQueue(myqueue);
	
	
	
	return 0;
}

 
