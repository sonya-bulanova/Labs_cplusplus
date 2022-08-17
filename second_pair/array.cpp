#include <iostream>
#include <fstream>

using namespace std;
int BinarySearch(int arr[100], int idx, int search){
  int l = 0;
  int r = idx;
  int m;
  while (l <= r){
    m = (l + r) / 2;
    if (arr[m] == search){
      return m;
    }
    else if (arr[m] > search) {
      r = m - 1;
    }
    else if (arr[m] < search){
      l = m + 1;
    }
  }
  return m;
}

int main(){
  ifstream in;
  in.open("binning.txt");
  int nLines = 0;
  int bord, num;
  int ary[100];

  while (in >> bord){
    ary[nLines] = bord;
    //cout << ary[nLines] << '\n';
    nLines++;
  }
  in.close();

  cout << "Enter element: ";
  cin >> num;
  cout << BinarySearch(ary, nLines, num) << '\n';
}
