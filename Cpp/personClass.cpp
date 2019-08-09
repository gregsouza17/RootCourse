#include <iostream>
#include <string.h>

class Person{
public:
  int m_id;
private:
  int m_age;
  std::string m_name;
  std::string m_occupation; 
public:
  Person(std::string name, std::string occupation,
	 int age, int id) :
    m_name(name), m_occupation(occupation), m_age(age), m_id(id)
  {
    std::cout << "Hi, I'm the constructorn !!!!! \n \n";
    //Nothing goes here  
  }

  void Print(){
    std::cout<< m_name << "\t Age: " << m_age <<"\t id: " <<
      m_id << "\t Occupation: " << m_occupation << "\n";
  }

  std::string GetName(){
    return m_name;
  }

  int GetId(){
    return m_id;
  }
  
  
};
