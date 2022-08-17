#include <iostream>
#include <cstdlib>
using namespace std;

typedef int DynamicArrayValueType_t;

class DynamicArray{
public:

  void PrintArray(const ValueType_t * p, const size_t nElements){
    cout << "Array: ";
    for (size_t i = 0; i < nElements; i++){
      cout << p[i] << ", ";
    }
    cout << '\n';
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
    cout << "Sorted Array: ";
    for (int i = 0; i < nElements; i++){
      cout << p[i] << ", ";
    }
    cout << '\n';
  }

  void ResizeArray(ValueType_t * p, size_t & nElements, const size_t nElementsNew){
    cout << "New Array: ";
    for (size_t i = nElements; i < nElementsNew; i++){
      p[i] = 0;
    }
    for (size_t i = 0; i < nElementsNew; i++){
      cout << p[i] << ", ";
    }
    cout << '\n';
  }

  void AppendArray(ValueType_t * p, size_t & nElements, ValueType_t Element){
    cout << "With Extra Elements: ";
    for (size_t i = nElements; i < nElements + 1; i++){
      p[i] = Element;
    }
    for (size_t i = 0; i < nElements + 1; i++){
      cout << p[i] << ", ";
    }
    cout << '\n';
  }

  ~DynamicArray() {}
};

int main(){
  size_t nElements;
  size_t newsize;
  size_t extrael;

  DynamicArrayValueType_t * p = new DynamicArrayValueType_t[100 * sizeof(int)];
  for (size_t i = 0; i < 100 * sizeof(int); i++){
    p[i] = 0;
  }

  cout << "Enter array size: ";
  cin >> nElements;
  for (int i = 0; i < nElements; i++){
      p[i] = rand() %10000;
  }
  DynamicArray printarray;

  printarray.PrintArray(p, nElements);
  cout << '\n';
  printarray.SortArray(p, nElements);
  cout << '\n';
  newsize = nElements * 1.5;
  printarray.ResizeArray(p, nElements, newsize);
  cout << '\n';
  cout << "Enter extra element: ";
  cin >> extrael;
  printarray.AppendArray(p, nElements, extrael);
  cout << '\n';

  delete [] p;
}
