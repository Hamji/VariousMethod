#include <stdio.h>

void SelectionSort(int a[])
{
	int small, temp;
	for (int i = 0; i < 9; i++)
	{
		// a[i] 를 먼저 제일 작은놈으로 ㄱㄱ
		small = i;
		for(int j = i + 1; j < 10; j++)
		{
			// a[j] 가 더 작으면 걔가 small
			if( a[j] < a[small])
				small = j;
		}	
		
		//small로 정해진애와 a[i] 랑 체인지
		temp = a[small];
		a[small] = a[i];
		a[i] = temp;
	}
}

int main()
{
	int arr[10] = {3, 7, 2, 1, 8, 4, 5, 6, 9, 0};
	
	SelectionSort(arr);
	
	for(int i = 0; i < 10; i ++)
		printf("%d ",arr[i]);
    printf("\n");
	
	return 0;
}