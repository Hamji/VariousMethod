#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *right;
	struct node *left;
};

struct node* head = NULL;

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

void findRepeat()
{
	struct node *cursor1, *cursor2, *temp;
	struct node *reList = NULL;
	int rep;
	for (cursor1 = head; cursor1->right != NULL; cursor1 = cursor1->right)
	{
		rep = cursor1->data;
		for (cursor2 = cursor1->right; cursor2 != NULL; cursor2 = cursor2->right)
		{
			if (cursor2->data == rep)
			{
				temp = (struct node*) malloc(sizeof(struct node));
				temp->data = rep;
				if (reList == NULL)
				{
					temp->right = reList;
					reList = temp;
				}
				else
				{
					temp->right = reList;
					reList->left = temp;
					reList = temp;
				}
				reList->left = NULL;
			}
		}
	}
	if (reList != NULL)
	{
		for (cursor1 = reList; cursor1 != NULL; cursor1 = cursor1->right)
		{
			rep = cursor1->data;
			for (cursor2 = cursor1; cursor2->right != NULL; cursor2 = cursor2->right)
			{
				if (cursor2 == cursor1)
					continue;
				if (cursor2->data == rep)
				{
					temp = cursor2;
					cursor2->right->left = cursor2->left;
					cursor2->left->right = cursor2->right;
					cursor2 = cursor2->left;
					free(temp);
				}
			}
			if (cursor2->right == NULL && cursor2->data == rep && cursor1 != cursor2)
			{
				cursor2->left->right = NULL;
				free(cursor2);
			}
		}
		for (cursor1 = reList; cursor1->right != NULL; cursor1 = cursor1->right);
		for (; cursor1 != NULL; cursor1 = cursor1->left)
			printf("%d ", cursor1->data);
		printf("\n");
	}
}

int main()
{
	//리스트 초기화
	Insert(5);
	Insert(2);
	Insert(5);
	Insert(9);
	Insert(-1);
	Insert(0);
	Insert(10);
	Insert(10);
	Insert(5);

	findRepeat();

	return 0;
}