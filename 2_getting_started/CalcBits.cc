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

int* calcBits(int arrayA[], int arrayB[], int n) {
  int *arrayC;
  arrayC = new int[n+1];
  int i;
  int carry = 0;
  int v;
  for (i = 0; i < n; i++) {
    v = arrayA[i] + arrayB[i] + arrayC[i];
    arrayC[i] = v % 2;
    if (v >= 2)
      arrayC[i+1] = 1;
  }
  return arrayC;
}

int main() {
    int arrA[] = {12, 11, 13, 5, 6, 8, 10, 12, 44, 56, 90};
    int arrB[] = {16, 21, 22, 28, 7, 10, 13, 18, 44, 60, 90};
    int n = sizeof(arrA)/sizeof(arrA[0]);
    int *res;
    res = calcBits(arrA, arrB, n);
    printArray(res, n+1);
    return 0;
}
