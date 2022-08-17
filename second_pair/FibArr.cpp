//fibonacci trough array
#include <iostream>
using namespace std;

int main(){
  int n;
  size_t Fib[10000];
  cout << "Enter number: ";
  cin >> n;
  for (int i = 0; i < n; i++){
    Fib[0] = 0;
    Fib[1] = 1;
    if (i > 1){
      Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
    cout << "For " << i + 1 << " " << "Fibonacci is: " << Fib[i] << '\n';
  }
}
