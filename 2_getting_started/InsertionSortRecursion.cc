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

void insertionSortNondecreaseRec(int arr[], int n) {
  if (n <= 1)
    return;
  printf("再起順番 %d \n", n);
  insertionSortNondecreaseRec(arr, n - 1);

  printArray(arr, n);

  int key = arr[n - 1];
  int i = n - 1 - 1;
  while (i >= 0 && arr[i] > key) {
    arr[i+1] = arr[i];
    i--;
  }
  arr[i + 1] = key;
}

int main() {
  // 8.times.map { rand(100) }
  int arr[] = {27, 11, 2, 18, 44, 43, 79, 25};
  // sizeofはメモリサイズを調べる
  // 配列のメモリサイズを一個目の要素(どれでもよさそうだが)の
  // メモリサイズで割ることで配列の要素数がわかる
  // https://qiita.com/yz2cm/items/56f88e606083c710a832
  int n = sizeof(arr)/sizeof(arr[0]);
  insertionSortNondecreaseRec(arr, n);
  printArray(arr, n);
  return 0;
}
