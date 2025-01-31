// #include <stdio.h>
//   void revereArray (int arr[],int n);
//  void printArray (int arr[],int n);
//  int main() {
//   int arr[] = {1,2,3,4,5};

//   revereArray(arr,5);
//   printArray(arr,5);
//   return 0;
//  }
//  void printArray (int arr[],int n) {
//   for (int i = 0; i < n; i++){
//     printf("%d ", arr[i]);
//   }
//  }
//  void revereArray (int array[],int n) {
// int firstVal;
// int j = n-1, i = 0;
//   while(i != n/2) {
//      firstVal = array[i];
//     array[i] = array[j];
//     array[j] =  firstVal;
//     i++;
// j--;

//     }
//  }

#include <stdio.h>
  void revereArray (int arr[],int n);
 void printArray (int arr[],int n);
 int main() {
  int arr[] = {1,2,3,4,5};

  revereArray(arr,5);
  printArray(arr,5);
  return 0;
 }
 void printArray (int arr[],int n) {
  for (int i = 0;i<5;i++){
    printf("%d ",arr[i]);
  }
 }
 void revereArray(int array[],int n) {
    int last_limit = n - 1;
  for (int i = 0;i<n/2;i++) {
    
    int firstVal = array[i];
    int secondVal = array[last_limit];
    array[i] =  secondVal;
    array[last_limit] = firstVal;
    last_limit--;


    }
 }