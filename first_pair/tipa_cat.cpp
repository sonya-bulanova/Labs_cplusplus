#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define PROGRAM_2
#define BUFFER_SIZE 500

int main(){
  const char * filename = "test.txt";
  ifstream in(filename);
  char buffer[BUFFER_SIZE] = " ";

#if defined (PROGRAM_1)
  const size_t nElements = 10;
  for (size_t idx = 0; idx < nElements; idx++){
    in >> buffer;
    std::cout << idx << ")" << buffer << '\n';
  }
#elif defined (PROGRAM_2)

  double pt[20] = {};
  double raa[20] = {};
  double eraa[20] = {};

  size_t nLines = 0;
  in >> nLines;
  in >> buffer >> buffer >> buffer;
  for (size_t idx = 0; idx < nLines; idx++){
    in >> pt[idx] >> raa[idx] >> eraa[idx];
  }
  for (size_t idx = 0; idx < nLines; idx++){
    cout << pt[idx] << ' ' << raa[idx] << ' ' << eraa[idx];
    cout << '\n';
  }
#elif defined(PROGRAM_3)

 double pt[20] = {};
 double raa[20] = {};
 double eraa[20] = {};

 size_t nLines = 0;
 in >> buffer;
 in >> buffer >> buffer >> buffer;
 while (in >> pt[nLines] >> raa[nLines] >> eraa[nLines]){ //eof -- end of file
   nLines++;
 }
 for (size_t idx = 0; idx < nLines; idx++){
   cout << pt[idx] << ' ' << raa[idx] << ' ' << eraa[idx];
   cout << '\n';
 }

#elif defined(PROGRAM_4)

 size_t nLines = 0;
 char symbol = ' ';
 while (in.get(symbol)){
   nLines++;
   cout << '(' << symbol << ')';
 }
 cout << '\n';

#elif defined(PROGRAM_5)

 size_t nLines = 0;
 bool ifPrintNumberOfLine = false;
 while (in.getline(buffer, BUFFER_SIZE, '\n')){
   nLines++;
   //ifPrintNumberOfLine = true;
   if (ifPrintNumberOfLine){
     cout << setw(10) << setfill(' ') << nLines;
     cout << ' ';
   }
   cout << buffer << '\n';
 }
 cout << '\n';

#endif

return 0;
}
