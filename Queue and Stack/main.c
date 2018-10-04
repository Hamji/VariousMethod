#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
	char data;
	struct node *next;
} node;

typedef struct  Stack {
	int count;
	int Max;
	struct node* top;
} Stack;

typedef struct Queue {
	int count;
	int Max;
	node *first;
} Queue;

Stack *stackCreate(int maxSize)
{
	//이상한 수 입력시 NULL 반환
	if (maxSize < 0)
		return NULL;

	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->count = 0; stack->Max = maxSize; stack->top = NULL;

	return stack;
}

int isEmpty(Stack *stack)
{
	if (stack->count == 0)
		return TRUE;
	else
		return FALSE;
}

int isFull(Stack * stack)
{
	if (stack->Max == stack->count)
		return TRUE;
	else
		return FALSE;
}

int Push(Stack *stack, char item)
{

	if (!isFull(stack))
	{
		node *temp = (node*)malloc(sizeof(node));
		temp->data = item; temp->next = stack->top;
		stack->top = temp;
		stack->count++;
		return TRUE;
	}
	else
		return FALSE;
}

char Pop(Stack *stack)
{
	if (!isEmpty(stack))
	{
		node *temp = stack->top;
		char tnum = stack->top->data;
		stack->top = stack->top->next;
		free(temp);
		stack->count--;
		return tnum;
	}
	else
		return FALSE;
}

Queue *queueCreate(int maxSize)
{
	if (maxSize < 0)
		return NULL;

	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->count = 0; queue->Max = maxSize; queue->first = NULL;

	return queue;
}

int IsEmpty(Queue *queue)
{
	if (queue->count == 0)
		return TRUE;
	else
		return FALSE;
}

int IsFull(Queue * queue)
{
	if (queue->Max == queue->count)
		return TRUE;
	else
		return FALSE;
}

int Enqueue(Queue * queue, char item)
{
	if (!IsFull(queue))
	{
		node *temp, *cursor;
		temp = (node*)malloc(sizeof(node));
		temp->data = item; temp->next = NULL;
		queue->count++;
		if (queue->first == NULL)
		{
			queue->first = temp;
			return TRUE;
		}
		for (cursor = queue->first; cursor->next != NULL; cursor = cursor->next);
		cursor->next = temp;
		return TRUE;
	}
	else
		return FALSE;
}

char Dequeue(Queue * queue)
{
	if (!IsEmpty(queue))
	{
		node *temp = queue->first;
		char tnum = temp->data;
		queue->first = queue->first->next;
		free(temp);
		queue->count--;
		return tnum;
	}
	else
		return FALSE;
}
int reverseQueue(Queue *queue)
{
	Stack *stack = stackCreate(queue->count);
	int tcount = queue->count;
	for (int i = 0; i < tcount; i++)
		Push(stack, Dequeue(queue));
	for (int i = 0; i < tcount; i++)
		Enqueue(queue, Pop(stack));
	return TRUE;
}
int main()
{
	Queue *queue = queueCreate(4);

	Enqueue(queue, 'a');
	Enqueue(queue, 'b');
	Enqueue(queue, 'c');
	Enqueue(queue, 'd');

	printf("Queue를 Reverse 전\n");
	for (node *cursor = queue->first; cursor != NULL; cursor = cursor->next)
		printf("%c ", cursor->data);
	printf("\n");

	reverseQueue(queue);

	printf("Queue를 Reverse 후\n");
	for (node *cursor = queue->first; cursor != NULL; cursor = cursor->next)
		printf("%c ", cursor->data);
	printf("\n");

	return 0;
}