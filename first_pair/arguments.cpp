#include <iostream>
using namespace std;
int main(int argc, char ** argv){
  //std::cout << "Hello, work :( \n";
  //std::string input = "";
  //std::cin >> input;
  //std::cout << "Your input: " << input << std::endl;
  //return 0;

    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    int c = a + b;
    int d = a * b;
    cout << "Сумма чисел = " << c << endl;
    cout << "Произведение чисел = " << d << endl;
    return 0;
}
