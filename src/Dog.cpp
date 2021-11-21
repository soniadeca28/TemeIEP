#include <../inc/Dog.hpp>

Dog::Dog() : Pet()
{
    walksPerDay_ = 3;
    coatLength_ = "short";
    coatColour_ = "black";
}

Dog::Dog(std::string name, std::string gender, int age, bool isPureBreed, std::string image,
    int walksPerDay, std::string coatLength, std::string coatColour) : 
    Pet(name, gender, age, isPureBreed, image)
{
    walksPerDay_ = walksPerDay;
    coatLength_ = coatLength;
    coatColour_ = coatColour;
}

Dog::Dog(const Dog &dog) : Pet(dog)
{
    walksPerDay_ = dog.walksPerDay_;
    coatLength_ = dog.coatLength_;
    coatColour_ = dog.coatColour_;
}

Dog::~Dog()
{
    std::cout<<"Dog destructor!"<<std::endl;
}

int Dog::getWalksPerDay()
{
    return walksPerDay_;
}

std::string Dog::getCoatLength()
{
    return coatLength_;
}

std::string Dog::getCoatColour()
{
    return coatColour_;
}

Dog &Dog::operator=(const Dog &dog)
{
    Pet::operator=(dog);
    walksPerDay_ = dog.walksPerDay_;
    coatLength_= dog.coatLength_;
    coatColour_ = dog.coatColour_;

    return *this;
}

void Dog::printInfo()
{
   std::cout<<"It's a dog!"<<"\n";
    Pet::printInfo();
    std::cout<<"How many walks per day does this pet need: "<<walksPerDay_<<std::endl
            <<"Pet coat length: "<<coatLength_<<std::endl
            <<"Pet coat colour: "<<coatColour_<<std::endl;
}