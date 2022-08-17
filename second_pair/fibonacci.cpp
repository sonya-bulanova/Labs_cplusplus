//fibonacci
#include <iostream>
using namespace std;

constexpr size_t FibNum(size_t golden_path){
  return (golden_path <= 1) ? golden_path : FibNum(golden_path -1) + FibNum(golden_path - 2);
}

int main(){
  size_t n;
  int Fib;
  cout << "Enter number: " << '\n';
  cin >> n;
  for (int i = 0; i < n; i++){
    cout << "For " << i << " " << "Fibonacci is: " << FibNum(i) << '\n';
  }
}
