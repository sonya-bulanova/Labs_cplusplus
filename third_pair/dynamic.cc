#include <cstdlib>
#include <stdint.h>
#include <stdio.h>

typedef int ValueType_t;

void PrintArray(const ValueType_t * p, const size_t nElements){
  printf("Array: ");
  for (size_t i = 0; i < nElements; i++){
    printf("%5i", p[i]);
  }
  printf("\n");
}

void StupidSort(int *arr, int left, int right){
  int i = left, j = right;
  int cng, pivot = arr[(left+right)/2];
  while (i <= j)
  {
      while (arr[i] < pivot) i++;
      while (arr[j] > pivot) j--;

      if (i <= j)
      {
          if (arr[i] > arr[j])
          {
              cng = arr[i];
              arr[i] = arr[j];
              arr[j] = cng;
          }
          i++; j--;
      }
  }
  if (left < j) StupidSort (arr, left, j);
  if (i < right) StupidSort (arr, i, right);
}

void SortArray(ValueType_t * p, const size_t nElements){
  StupidSort(p, 0, nElements);
  printf("Sorted Array: ");
  for (int i = 0; i < nElements; i++){
    printf("%5i", p[i]);
  }
  printf("\n");
}

void ResizeArray(ValueType_t * p, size_t & nElements, const size_t nElementsNew){
  printf("New Array: ");
  for (size_t i = nElements; i < nElementsNew; i++){
    p[i] = 0;
  }

  for (size_t i = 0; i < nElementsNew; i++){
    printf("%5i", p[i]);
  }
  printf("\n");
}

void AppendArray(ValueType_t * p, size_t & nElements, ValueType_t Element){
  printf("With Extra Elements: ");
  for (size_t i = nElements; i < nElements + 1; i++){
    p[i] = Element;
  }

  for (size_t i = 0; i < nElements + 1; i++){
    printf("%5i", p[i]);
  }
  printf("\n");
}

int main(){
  size_t arrsize;
  size_t newsize;
  size_t extrael;

  ValueType_t * arr = new ValueType_t[100 * sizeof(int)];
  for (size_t i = 0; i < 100 * sizeof(int); i++){
    arr[i] = 0;
  }
  printf("Enter array size: ");
  scanf("%zu", &arrsize);
  for (int i = 0; i < arrsize; i++){
      arr[i] = rand() %1000;
  }

  PrintArray(arr, arrsize);
  printf("\n");
  SortArray(arr, arrsize);
  printf("\n");
  newsize = arrsize * 1.5;
  ResizeArray(arr, arrsize, newsize);
  printf("\n");
  printf("Enter extra element: ");
  scanf("%zu", &extrael);
  AppendArray(arr, arrsize, extrael);
  delete [] arr;
}
