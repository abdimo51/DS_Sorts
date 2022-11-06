// C program for insertion sort
#include <math.h>
#include <stdio.h>


void insert_sort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
	
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// a function to print
// an arr of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver Code:
int main()
{
	int arr[] = {56, 88, 95, 87, 59, 61, 12, 53};
	int n = sizeof(arr) / sizeof(arr[0]);

	insert_sort(arr, n);
	printArray(arr, n);

	return 0;
}
