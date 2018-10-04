#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
};

struct node* head;

int getCount(int k)
{
	int count = 0;
	struct node *cursor;
	for (cursor = head; cursor != NULL; cursor = cursor->right)
		if (cursor->data == k)
			count++;
	
	return count;
}

int getNth(int k)
{
	struct node *cursor;
	int many = 1;
	for (cursor = head; cursor->right != NULL; cursor = cursor->right)
		many++;
	if (k > many || k <= 0)
	{
		printf("오류: -1을 return 합니다.\n");
		return -1;
	}
	for (int i = 1; i < k; i++)
		cursor = cursor->left;
	return cursor->data;
}

void Insert(int k)
{
	struct node *cursor, *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	temp->data = k; temp->right = NULL;
	if (head == NULL)
	{
		temp->left = NULL;
		head = temp;
	}
	else
	{
		for (cursor = head; cursor->right != NULL; cursor = cursor->right);
		temp->left = cursor;
		cursor->right = temp;
	}
}

int main()
{	
	//리스트 초기화
	Insert(3);
	Insert(0);
	Insert(999);
	Insert(-2);
	Insert(4);
	Insert(3);
	Insert(55);
	Insert(-1);
	Insert(76);

	printf("%d\n", getCount(3));
	printf("%d\n", getNth(3));

	return 0;
}

