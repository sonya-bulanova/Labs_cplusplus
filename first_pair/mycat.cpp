#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
#define BUFFER_SIZE 500
int main(int argc, char * argv[]){
  char buffer[BUFFER_SIZE] = " ";
  size_t nLines = 0;
  const char * filename = argv[1];
  ifstream inf(filename);

  if (argc == 1){
    cout << "Usage: mycat [name of file] [options]" << '\n';
  }

  bool ifPrintNumberOfLine = false;

  for (int i = 0; i < argc; i++){
    int comp = strcmp(argv[i], "-n");
    if (comp == 0){
      ifPrintNumberOfLine = true;
    }
  }

    while (inf.getline(buffer, BUFFER_SIZE, '\n')){
        nLines++;
        if (ifPrintNumberOfLine){
          cout << setw(10) << setfill(' ') << nLines << ' ';
          cout << ' ';
        }
        cout << buffer << '\n';
      }
      cout << '\n';
  }
