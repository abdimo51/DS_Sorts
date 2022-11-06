// C-program to perform a selection sort of array!

#include <stdio.h>

void swap(int *ab, int *bc)
{
	int temp = *ab;
	*ab = *bc;
	*bc = temp;
}

void sel_sort(int arr[], int x)
{
	int i, j, min_indx;

	// one by one sort unsorted positions of the array
	for (i = 0; i < x-1; i++)
	{
		// Choose the min element in the array
		min_indx = i;
		for (j = i+1; j < x; j++)
		if (arr[j] < arr[min_indx])
			min_indx = j;

		/* switch the sorted min element with the element in the first index */
		if(min_indx != i)
			swap(&arr[min_indx], &arr[i]);
	}
}

// An Array Function
void array(int arry[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arry[i]);
	printf("\n");
}

// Driver code
int main()
{
	int arr[] = {89, 35, 24, 29, 9, 45, 98, 46, 85, 51, 8, 86, 69};
	int n = sizeof(arr)/sizeof(arr[0]);
	sel_sort(arr, n);
	printf("The sel-sorted array is : \n");
	array(arr, n);
	return 0;
}
