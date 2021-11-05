#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <../inc/Pet.hpp>

class Cat : public Pet
{
public:
    Cat();
    Cat(std::string name, std::string gender, int age, bool isPureBreed,
    bool isLitterBoxTrained, std::string furLength, std::string furColour);
    Cat(const Cat &cat) = delete;
    ~Cat();
    bool getIsLitterBoxTrained();
    std::string getFurLength();
    std::string getFurColour();
    Cat &operator=(const Cat &cat);
    void printInfo();

private:
    bool isLitterBoxTrained_;
    std::string furLength_;
    std::string furColour_;

};


#endif