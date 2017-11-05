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

int lineraSearch(int array[], int n, int target) {
  int i;
  for (i = 0; i < n; i++)
    if(array[i] == target)
      return i;
  return -1;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 8, 10, 12, 44, 56, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 12;
    int res = lineraSearch(arr, n, target);
    printInfo("Result", res);
    return 0;
}
