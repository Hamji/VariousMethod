#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
	int data;
	struct node *next;
} node;

typedef struct  Stack {
	int count;
	int Max;
	struct node* top;
} Stack;

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

int Push(Stack *stack,int item)
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

int Pop(Stack *stack)
{
	if (!isEmpty(stack))
	{
		node *temp = stack->top;
		int tnum = temp->data;
		stack->top = stack->top->next;
		free(temp);
		stack->count--;
		return tnum;
	}
	else
		return FALSE;
}
//  숫자열이 palindrome이면 Yes 출력후 TRUE 아니면 No 출력후 FALSE 리턴한다.
int isPalindrome(Stack *stack)
{
	Stack *temp = stackCreate((stack->count) / 2);
	node *tnode = stack->top;
	
	//애초에 숫자열 없으면 없다는 말 출력 후 FALSE 리턴
	if (stack->count == 0)
	{
		printf("숫자열이 없습니다.\n");
		return FALSE;
	}

	for (int i = 0; i < stack->count; i++)
	{
		printf("%d", tnode->data);
		tnode = tnode->next;
	}
	printf(": ");

	for (int i = 0; i < temp->Max; i++)
		Push(temp, Pop(stack));

	if ((stack->count + temp->Max) % 2 != 0)
		Pop(stack);

	while (stack->count != 0)
	{
		if (Pop(stack) != Pop(temp))
		{
			printf("No.\n");
			return FALSE;
		}
	}
	printf("Yes.\n");
	return TRUE;
}

int main()
{
	struct Stack *stack1, *stack2, *stack3;
	
	stack1 = stackCreate(4);
	stack2 = stackCreate(5);
	stack3 = stackCreate(4);

	Push(stack1, 4);
	Push(stack1, 3);
	Push(stack1, 2);
	Push(stack1, 1);

	Push(stack2, 1);
	Push(stack2, 2);
	Push(stack2, 3);
	Push(stack2, 2);
	Push(stack2, 1);

	Push(stack3, 1);
	Push(stack3, 0);
	Push(stack3, 0);
	Push(stack3, 1);

	isPalindrome(stack1);
	isPalindrome(stack2);
	isPalindrome(stack3);

	return 0;
}