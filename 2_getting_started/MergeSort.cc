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

// 結合
// 要素数 n = r - p + 1
// p ≦q < r
// arr[p..q] と arr[q+1..r] の要素はソート済み
// 最終的にarr[q..r]がソート済になる
void merge(int arr[], int p, int q, int r) {
  int i, j;
  int n1 = q - p + 1; // Lの要素数
  int n2 = r - q + 1; // Rの要素数 最後に一つ余計に0を入れておく
  // 一時的に退避する配列
  int L[n1], R[n2];

  // LとRにデータをコピー
  for (i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[q + 1 + j];

  int k;
  i = 0;
  j = 0;
  k = p;

  // LとRの両方に要素が残っている状態
  // LとRの要素を比較して小さい方を入れ替えていく
  while(i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  //while(i < n1) {
  //  printf("%s", "n1 \n");
  //  arr[k] = L[i];
  //  i++;
  //  k++;
  //}

  // Rには最後にかならず0が入っているので正の整数であれば
  // 残っているのはRしかないのでこのループだけで問題ない
  while(j < n2) {
    //printf("%s", "n2 \n");
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int p, int r) {
  if (p < r) {
    // https://wandbox.org/permlink/GmHVse84j5PZybHK
    // オーバーフローの防止
    int q = p + (r - p)/ 2;
    mergeSort(arr, p , q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
  }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 99, 100, 5, 67};
    // sizeofはメモリサイズを調べる
    // 配列のメモリサイズを一個目の要素(どれでもよさそうだが)の
    // メモリサイズで割ることで配列の要素数がわかる
    // https://qiita.com/yz2cm/items/56f88e606083c710a832
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    mergeSort(arr, 0,  n-1);
    printArray(arr, n);
    return 0;
}
