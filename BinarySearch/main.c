#include <stdio.h>	
#include <stdlib.h>

int destination;

//이진 탐색을 이용해서 찾을 수 있다.
int BinarySearch(int start, int end)
{
	const int mean = (start + end) / 2;
	
	if ( destination > mean)
		return BinarySearch(mean, end);
	else if (destination < mean)
		return BinarySearch(start, mean);
	else
		return  (end + start) / 2;
}

int main() 
{

	destination = 124;
	
	printf("Setting value is %d \n\n",destination);
	
	printf("Result is %d \n", BinarySearch(0,1000));

	return 0;
}