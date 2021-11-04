#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <../inc/Pet.hpp>

class Dog : public Pet
{
public:
    Dog();
    Dog(std::string name, std::string gender, int age, bool isPureBreed,
    int walksPerDay, std::string coatLength, std::string coatColour);
    Dog(const Dog &dog);
    ~Dog();
    int getWalksPerDay();
    std::string getCoatLength();
    std::string getCoatColour();
    Dog &operator=(const Dog &dog);
    void printInfo();

private:
    int walksPerDay_;
    std::string coatLength_;
    std::string coatColour_;

};


#endif