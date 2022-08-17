//inheritance

#include <iostream>

class Person {
  std::string fName;
  std::string fSurename;
  unsigned short fAge;

public:
  Person(
    const std::string & name,
    const std::string & surename,
    unsigned short age): fName(name), fSurename(surename), fAge(age){
      std::cout << "New person registered: " << std::endl;
      //Print();
    }

  Person();
  Person(const Person &) = default;
  Person & operator = (const Person &) = delete;
  virtual ~Person(){
    std::cout << "Person deleted: " << std::endl;
  };

  std::string GetName() const { return fName; }
  std::string GetSurename() const { return fSurename; }
  unsigned short GetAge() const { return fAge; }
  void Print() const{
    std::cout << "\tName: " << fName << std::endl;
    std::cout << "\tSurename: " << fSurename << std::endl;
    std::cout << "\tAge: " << fAge << std::endl;
  }
};

class UniversityInhabitant: public Person{
  unsigned int fId;
public:
  UniversityInhabitant(std::string name,
    std::string surename,
    unsigned short age,
    unsigned int  id) : Person(name, surename, age), fId(id){
      std::cout << "New UniversityInhabitant registered ";
    }
    ~UniversityInhabitant(){
      std::cout << "UniversityInhabitant deleted" << std::endl;
    }
    unsigned int GetId() const{
      return fId;
    }
};

class Student: public UniversityInhabitant{
  std::string fGroupNo;
public:
  Student(
    std::string name,
    std::string surename,
    unsigned short age,
    std::string groupNo,
    unsigned int id) : UniversityInhabitant(name, surename, age, id), fGroupNo(groupNo)
    {
      std::cout << "New Student Registered" << std::endl;
    }
    //std::string GetGroupNo() const {return fGroupNo;}
};

class Lecturer: public Person{
  std::string fDegree;
public:
  Lecturer(
    std::string name,
    std::string surename,
    std::string degree,
    unsigned int id) : Person(name, surename, id), fDegree(id)
    {
      std::cout << "New Lecturer registered" << std::endl;
    }
};

int main(){
  Person p1("Rose", "Arago", 21);
  p1.Print();
  Person * p2 = new Person("Alice", "Arago", 65);
  p2 -> Print();
  delete p2;
  return 0;
}
