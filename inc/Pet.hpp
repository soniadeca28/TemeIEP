#ifndef PET_HPP
#define PET_HPP

#include<iostream>

class Pet
{
public:
    Pet();
    Pet(std::string name, std::string gender, int age, bool isPureBreed);
    Pet(const Pet &pet);
    virtual ~Pet() = 0;
    std::string getName();
    std::string getGender();
    int getAge();
    bool getIsPureBreed();
    Pet &operator=(const Pet &pet);
    virtual void printInfo();
    virtual std::string getFurLength() { return ""; }
    virtual std::string getFurColour() { return ""; }
    virtual bool getIsLitterBoxTrained() { return 0; }

protected:
    std::string name_;
    std::string gender_;
    int age_;
    bool isPureBreed_;
};

#endif