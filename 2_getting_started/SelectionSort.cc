#include <stdio.h>
#include <iostream>
#include <string>

// http://www.geeksforgeeks.org/linear-search/
void printArray(int arr[], int n) {
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

void printInfo(std::string test, int n) {
  printf("[INFO] %s %d \n", test.c_str(), n);
}

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int array[], int n) {
  int j, i;
  // 一時的に退避する変数
  int key, min_index;

  for (i = 0; i < n - 1; i++) {
      min_index = i;
      for (j = i + 1; j < n; j++)
        if (array[j] < array[min_index])
          min_index = j;
      swap(&array[min_index], &array[i]);
  }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 8, 10, 12, 44, 56, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}

