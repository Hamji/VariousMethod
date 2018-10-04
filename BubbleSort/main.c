#include <stdio.h>

void BubbleSort(int a[])
{
	int temp;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9-i; j++)
		{
			if( a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
int main()
{
	int arr[10] = {3, 7, 2, 1, 8, 4, 5, 6, 9, 0};
	
	BubbleSort(arr);
	
	for(int i = 0; i < 10; i ++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}