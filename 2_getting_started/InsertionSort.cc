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

void insertionSortNondecrease(int array[], int n) {
  int j, i;
  // 一時的に退避する変数
  int key;
  for (j = 1; j < n; j++) {
    printInfo("j", j);
    printInfo("array[j]", array[j]);
    key = array[j];
    i = j - 1;
    while (i >= 0 && array[i] > key) {
      array[i+1] = array[i];
      i = i - 1;
    }
    printInfo("i", i);
    array[i + 1] = key;
  }
}

void insertionSortNonincrease(int array[], int n) {
  int j, i;
  // 一時的に退避する変数
  int key;
  for (j = 1; j < n; j++) {
    printInfo("j", j);
    printInfo("array[j]", array[j]);
    key = array[j];
    i = j - 1;
    while (i >= 0 && array[i] < key) {
      array[i+1] = array[i];
      i = i - 1;
    }
    printInfo("i", i);
    array[i + 1] = key;
  }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    // sizeofはメモリサイズを調べる
    // 配列のメモリサイズを一個目の要素(どれでもよさそうだが)の
    // メモリサイズで割ることで配列の要素数がわかる
    // https://qiita.com/yz2cm/items/56f88e606083c710a832
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSortNondecrease(arr, n);
    printArray(arr, n);
    insertionSortNonincrease(arr, n);
    printArray(arr, n);
    return 0;
}
