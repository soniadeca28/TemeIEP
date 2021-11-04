#include <../inc/Pet.hpp>

Pet::Pet()
{
    std::cout<<"Created a pet !"<<std::endl;
   name_ = "No Name";
    gender_ = "Female";
    age_ = 0;
    isPureBreed_ = 0;
}

Pet::Pet(std::string name, std::string gender, int age, bool isPureBreed)
{
    std::cout<<"Created a pet !"<<std::endl;
    name_ = name;
    gender_ = gender;
    age_ = age;
    isPureBreed_ = isPureBreed;
}

Pet::Pet(const Pet &pet)
{
    std::cout<<"Created a pet !"<<std::endl;
    name_ = pet.name_;
    gender_ = pet.gender_;
    age_ = pet.age_;
    isPureBreed_ = pet.isPureBreed_;
}

Pet::~Pet()
{
    std::cout<<"Pet destructor"<<std::endl;
}

std::string Pet::getName()
{
    return name_;
}

std::string Pet::getGender()
{
    return gender_;
}

int Pet::getAge()
{
    return age_;
}

bool Pet::getIsPureBreed()
{
    return isPureBreed_;
}

Pet &Pet::operator=(const Pet &pet)
{
    name_ = pet.name_;
    gender_ = pet.gender_;
    age_ = pet.age_;
    isPureBreed_ = pet.isPureBreed_;
    return *this;
}

void Pet::printInfo()
{
    std::cout<<"Pet name : "<<name_<<std::endl
             <<"Pet gender : "<<gender_<<std::endl
             <<"Pet age : "<<age_<<std::endl
             <<"Is the pet pure breed : "<<std::boolalpha<<isPureBreed_<<std::endl;
}

