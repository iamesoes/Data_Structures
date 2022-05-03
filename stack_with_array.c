#include<stdio.h>
#include<stdlib.h>
#define MAX 15
typedef struct stack{
	int top;
	int count;
	int array[MAX];
}S; //we will S shortcut for this struct




int isEmpty(S *stack){
	if(stack->top==-1){
		printf("The stack is empty.\n");
		return 1; 
	}
	return 0;
}

int isFull(S *stack){
	if(stack->top==MAX-1){
		printf("The stack is full.\n");
		return 1; 
	}
	return 0;
}


int peek(S *stack){
	if(isEmpty(stack)){
		return -1; 
	}
	return stack->array[stack->top]; //we only show it. We do not pop it
}

void push(S *stack, int value){
	if(isFull(stack)){
		return;
	}
	
	stack->count++;
	stack->top++; //we firstly increase this since it started with -1 at main
	stack->array[stack->top]=value;
	printf("Pushing %d process is successfully done.\n",value);
	
}

void pop(S *stack){
	if(isEmpty(stack)){
		return;
	}
	printf("%d is removing...\n",stack->array[stack->top]);
	stack->top--; //still we have the value however we cannot reach thanks to this line
	stack->count--;
	printf("Popping process is successfully done.\n");
}

void printStack(S *stack){
	int i;
	printf("\nMy Stack: ");
	for(i=0;i<stack->count;i++){
		printf("%d ",stack->array[i]);
	}
	printf("\n-------right side is newer values------\n\n");
	
}

int main(){
	
	S *mystack = (S*)malloc(sizeof(S));
	if(mystack==NULL){
		printf("Allocation Error!");
		return -1;
	}
	
	mystack->count=0; //there is no element firstly
	mystack->top=-1; //it must not to show any index firstly
	
	push(mystack,5);
	push(mystack,4);
	push(mystack,9);
	printStack(mystack);
	pop(mystack);
	
	printStack(mystack);
	

	return 0;
}


