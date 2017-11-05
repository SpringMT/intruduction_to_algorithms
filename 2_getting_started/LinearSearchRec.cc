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

int binarySearch(int arr[], int start, int end, int target) {
  if (end >= start ) {
    int mid = start + (end - start) / 2;
    printInfo("mid", arr[mid]);
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearch(arr, start, mid - 1, target);
    return binarySearch(arr, mid + 1, end, target);
  }
  return -1;
}

int main() {
    int arr[] = {2, 18, 25, 27, 43, 44, 79};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 44;
    int res = binarySearch(arr, 0, n - 1, target);
    printInfo("Result", res);
    return 0;
}
