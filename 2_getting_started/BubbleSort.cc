#include <stdio.h>
#include <iostream>
#include <string>

void printArray(int arr[], int n) {
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

void printInfo(std::string test, int n) {
  printf("[INFO] %s %d \n", test.c_str(), n);
}

void bubbleSort(int arr[], int n) {
  if (n == 1) return;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1])
      std::swap(arr[i], arr[i + 1]);
  }
  bubbleSort(arr, n - 1);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 99, 100, 5, 67};
    // sizeofはメモリサイズを調べる
    // 配列のメモリサイズを一個目の要素(どれでもよさそうだが)の
    // メモリサイズで割ることで配列の要素数がわかる
    // https://qiita.com/yz2cm/items/56f88e606083c710a832
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
