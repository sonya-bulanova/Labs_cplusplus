//randomiser
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  ofstream out;
  out.open("unsorted.txt");
  if (out.is_open()){
    for (int i = 0; i < 200; i++){
      out << rand() %500 << '\n';
    }
  }
  out.close();
}
