#include "People & Creatures.h"
#include <string>


Person::Person(std::string name, std::string job, double age, Sex sex){
  this->name = name; 
  this->job = job;
  this->sex = sex;
  this->age = age;
}

 Person::~Person() {};
  

  // Methods // 

 void Person::sleep(double hours){
    this->slept = true;
    this->hours += 8;
  }; 
  
  void Person::eat(){};
  

