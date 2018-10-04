#include <stdio.h>

int Partition(int a[],int l, int r)
{
	int pivot, i, j, t;
	// 피벗을 첫번째 요소로 정하자
	pivot = a[l];
	
	// i 는 다음칸
	i = l + 1;
	// j 는 r 
	j = r;
	
	while(1)
	{
		while(a[i] <= pivot && i <= r)
			i++;
		
		while(a[j] > pivot)
			j--;
		
		if( i >= j)
			break;
		
		t = a[i]; a[i] = a[j]; a[j] = t;
	}
	t = a[l]; a[l] = a[j]; a[j] = t;
	
	return j;
}

void QuickSort(int a[],int l, int r)
{
	for(int i = 0; i < 10; i ++)
        printf("%d ",a[i]);
	printf("\n");
	
	int j;
	// l 하고 r 같으면 퀵소트 그만하자..;;
	if( l < r)
	{
		// 나누고 정복!!!
		j = Partition(a, l, r);
		
		// 나눈걸 통해 또다시 퀵소트
		QuickSort(a, l, j - 1);
		QuickSort(a, j + 1, r);
	}
	
}

int main()
{
	int arr[10] = {3, 7, 2, 1, 8, 4, 5, 6, 9, 0};
	
	QuickSort(arr,0,9);
		
	for(int i = 0; i < 10; i ++)
        printf("%d ",arr[i]);
    printf("\n");
	
	return 0;
}