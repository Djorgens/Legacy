#pragma once
#include <string>

enum Sex {Male, Female};
enum Job {Serf, Peasant, Farmer};


class Person
{
public:
    // Constructor // 
    Person(std::string name, std::string job, double age, Sex sex);
    virtual ~Person();

    // Variables // 
    Sex sex;
    double age;
    double hours = 0;
    std::string job;
    std::string name;
    bool slept = false;

    // Methods //
    virtual void sleep(double hours);
    virtual void eat();
    virtual Person* clone() const = 0;
   
};


