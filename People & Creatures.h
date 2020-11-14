#pragma once
#include <string>

enum Sex {Male, Female};


using namespace std;

class Person
{
public:
    string name;
    string job;
    double wealth; 
    string faction;
    int age; 
    int productivity;
    int education;
    int inheritor;
    int household;
    Sex sex;
    int hours;
    static int numOfPersons; 
  //--------Getters-------------//
    string GetName();
    string GetJob();
    Sex GetSex();
    int GetAge();
    int GetHours();
 //--------Setters-------------//
    void SetName(string name) {this->name = name;}
    void SetJob(string job) {this->job = job;}
    void SetWealth(double wealth) {this->wealth = wealth;}
    void SetAge(int age) {this->age = age;}
    void SetSex(Sex sex) {this->sex = sex;}
    static int GetNumOfPersons() {return numOfPersons;}

  //--------Constructors-------------//
   Person();
   ~Person();
   Person(string name, string job, int age, Sex sex);

};