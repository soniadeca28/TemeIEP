#include <../inc/Cat.hpp>

Cat::Cat() : Pet()
{
    isLitterBoxTrained_ = false;
    furLength_ = "No fur";
    furColour_ = "Grey";
}

Cat::Cat(std::string name, std::string gender, int age, bool isPureBreed, std::string image,
    bool isLitterBoxTrained, std::string furLength, std::string furColour) : 
    Pet(name, gender, age, isPureBreed, image)
{
    isLitterBoxTrained_ = isLitterBoxTrained;
    furLength_ = furLength;
    furColour_ = furColour;
}

Cat::Cat(const Cat &cat) : Pet(cat)
{
    isLitterBoxTrained_ = cat.isLitterBoxTrained_;
    furLength_ = cat.furLength_;
    furColour_ = cat.furColour_;
}

Cat::~Cat()
{
    std::cout<<"Cat destructor!"<<std::endl;
}

bool Cat::getIsLitterBoxTrained()
{
    return isLitterBoxTrained_;
}

std::string Cat::getFurLength()
{
    return furLength_;
}

std::string Cat::getFurColour()
{
    return furColour_;
}

Cat &Cat::operator=(const Cat &cat)
{
    Pet::operator=(cat);
    isLitterBoxTrained_ = cat.isLitterBoxTrained_;
    furLength_= cat.furLength_;
    furColour_ = cat.furColour_;

    return *this;
}

void Cat::printInfo()
{
    std::cout<<"It's a cat!"<<"\n";
    Pet::printInfo();
    std::cout<<"Is the pet litterbox trained: "<<std::boolalpha<<isLitterBoxTrained_<<std::endl
            <<"Pet fur length: "<<furLength_<<std::endl
            <<"Pet fur colour: "<<furColour_<<std::endl<<std::endl;
}