//lab5
#include <iostream>
using namespace std;

class Person {
protected:
  std::string fName;
  std::string fSurename;
  unsigned int fId;

public:
  Person(
    const std::string & name,
    const std::string & surename,
    unsigned int id): fName(name), fSurename(surename), fId(id){
      std::cout << "New person registered: " << std::endl;
    }
    virtual void Print() const{
      std::cout << "\tName: " << fName << std::endl;
      std::cout << "\tSurename: " << fSurename << std::endl;
      std::cout << "\tID: " << fId << std::endl;
    }

    virtual ~Person(){
      std::cout << "Person is deleted" << std::endl;
    };
};

class Student: public Person{
protected:
  std::string fGroupNo;
public:
  Student(
    std::string name,
    std::string surename,
    std::string groupNo,
    unsigned int id) : Person(name, surename, id), fGroupNo(groupNo)
    {
      std::cout << "New Student registered" << std::endl;
    }
    void Print() const{
      std::cout << "\tName: " << fName << std::endl;
      std::cout << "\tSurename: " << fSurename << std::endl;
      std::cout << "\tID: " << fId << std::endl;
      std::cout << "\tGroup ID: " << fGroupNo << std::endl;
    }

    ~Student(){
      std::cout << "Student deleted" << std::endl;
    }
};

class Lecturer: public Person{
protected:
  std::string fDegree;
public:
  Lecturer(
    std::string name,
    std::string surename,
    std::string degree,
    unsigned int id) : Person(name, surename, id), fDegree(degree)
    {
      std::cout << "New Lecturer registered" << std::endl;
    }

    void Print() const{
      std::cout << "\tName: " << fName << std::endl;
      std::cout << "\tSurename: " << fSurename << std::endl;
      std::cout << "\tID: " << fId << std::endl;
      std::cout << "\tDegree: " << fDegree << std::endl;
    }

    ~Lecturer(){
      std::cout << "Lecturer deleted" << std::endl;
    }
};

int main(){
  Person * student = new Student("Ivan", "Ivanov", "10123/1", 1);
  student -> Print();
  Person * lecturer = new Lecturer("Sergey", "Preobrasjensky", "docent", 0);
  lecturer -> Print();

  delete student;
  delete lecturer;
  return 0;
}
