#include <iostream>
#include <fstream>
using namespace std;
#define ARR_SIZE 500

void SortArray(int *arr, int left, int right){
  int i = left, j = right;
  int cng, mid = arr[(left+right)/2];
  do
  {
      while (arr[i] > mid) i++;
      while (arr[j] < mid) j--;

      if (i <= j)
      {
          //if (arr[i] < arr[j])
          //{
              cng = arr[i];
              arr[i] = arr[j];
              arr[j] = cng;
          //}
          i++; j--;
      }
  } while (i < j);
  if (left < j) SortArray (arr, left, j);
  if (i < right) SortArray (arr, i, right);
}

int main(){
  ifstream in;
  in.open("unsorted.txt");
  int nLines = 0;
  int bord;
  int arr[ARR_SIZE];

  cout << "unsorted array: ";
  while (in >> bord){
    arr[nLines] = bord;
    cout << arr[nLines] << ", ";
    nLines++;
  }
  in.close();

  cout << '\n';
  cout << "sorted array: ";
  SortArray(arr, 0, nLines);
  for (int i = 0; i < nLines; i++){
    cout << arr[i] << ", ";
  }
  cout << '\n';
}
