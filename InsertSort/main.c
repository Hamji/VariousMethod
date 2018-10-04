#include <stdio.h>

void InsertSort(int a[])
{
	int i, j, key;
	for ( i = 1; i < 10; i++)
	{
		
		key = a[i];
		j = i - 1;
		
		while(j >= 0 && a[j] > key)
		{
			a[j+1] = a[j];	
			j = j - 1;
		}
		
		a[j+1] = key;
	}
}

int main()
{
	int arr[10] = {3, 7, 2, 1, 8, 4, 5, 6, 9, 0};
	
	InsertSort(arr);
    
	
	for(int i = 0; i < 10; i ++)
		printf("%d ",arr[i]);
    printf("\n");
	
	return 0;
}