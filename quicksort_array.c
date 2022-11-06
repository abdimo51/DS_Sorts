// Quick sort in C

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to point the partition position
int partition(int array[], int low, int high) {
  
  // put the rightmost elements as a pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array and compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found then swap it with the greater element pointed by i
      
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
  
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// DriverCode
int main() {
  int data[] = {18, 17, 12, 11, 00, 19, 16};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted: \n");
  printArray(data, n);
  
  // do quicksort on data
  quickSort(data, 0, n - 1);
  
  printf("Sorted in ascending order: \n");
  printArray(data, n);
}