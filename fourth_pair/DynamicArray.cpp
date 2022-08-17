//DynamicArray.cpp

#include <iostream>
#include <cstdlib>
using namespace std;
using DynamicArrayValueType_t = int;

class DynamicArray{
private:
  size_t fSize;
  DynamicArrayValueType_t * fData;
public:
  DynamicArray(){
    fSize = 0;
    fData = nullptr;
    cout << "Default Constructor worked" << endl;
  } //default constructor

  DynamicArray(size_t n, const DynamicArrayValueType_t & val){
    fSize = n,
    fData = new DynamicArrayValueType_t[fSize];
    for (size_t idx = 0; idx < fSize; idx++){
      fData[idx] = val;
    }
    cout << "Array from " << n << " elements created" << endl;
  } //constructor with values

  DynamicArray(const DynamicArray & dyn_arr){
    fSize = dyn_arr.fSize,
    fData = new DynamicArrayValueType_t[fSize];
    for (size_t idx = 0; idx < fSize; idx++){
      fData[idx] = dyn_arr.fData[idx];
    }
    cout << "Copy constructor copied your object" << endl;
  } //copy constructor

  DynamicArray & operator = (const DynamicArray & dyn_arr){
    fSize = dyn_arr.fSize;
    fData = new DynamicArrayValueType_t[fSize];
    for (size_t idx = 0; idx < fSize; idx++){
      fData[idx] = dyn_arr.fData[idx];
    }
    cout << "Overload assignment operator created object" << endl;
    return * this;
  } //overload assignment operator

  size_t Size() const {return fSize;}
  DynamicArrayValueType_t Get(size_t idx) const {return fData[idx];}

  ~DynamicArray(){
    if (fData){
      delete [] fData;
      //cout << "Array deleted" << endl;
    }
  }

   void Resize(size_t NewSize){
     size_t n = NewSize;
     if (fSize < NewSize){
       for (size_t idx = fSize; idx < NewSize; idx++){
         fData[idx] = 0;
       }
       for (size_t idx = 0; idx < NewSize; idx++){
         cout << fData[idx] << ", ";
       }
       cout << endl;
     }
   }

   void Append(const DynamicArrayValueType_t & val){
     Resize(fSize++);
     fData[fSize - 1] = val;
   }

   void Print() const {
     for (size_t idx = 0; idx < fSize; idx++){
       cout << fData[idx] << ", ";
     }
     cout << endl;
   }

};

int main(){
  DynamicArray a1;
  a1.Print();
  cout << "================" << endl;
  DynamicArray a2(10, 60);
  a2.Print();
  cout << "================" << endl;
  DynamicArray a3(a2);
  a3.Print();
  cout << "================" << endl;
  DynamicArray a4(10, 9);
  DynamicArray a5;
  a5 = a4;
  cout << "================" << endl;
  a5.Resize(20);
  a5.Append(999);
  a5.Print();
  cout << "Element #10 is: " << a5.Get(10) << endl;
  return 0;
}
