#include <iostream>
#include <../inc/Pet.hpp>
#include <../inc/Cat.hpp>
#include <../inc/Dog.hpp>

int main()
{
    std::cout<<"Kitty:"<<std::endl;
    Cat kitty("Mrs. Paw","Female",2,false,"./kitty.jpg",true,"short","white");
    kitty.printInfo();
    std::cout<<std::endl;
    
    std::cout<<"Copy cat through copy constructor:"<<std::endl;
    Cat copyCat(kitty);
    copyCat.printInfo();
    std::cout<<std::endl;

    std::cout<<"Trying to assign the same cat"<<std::endl;
    copyCat= copyCat;
    copyCat.printInfo();
    std::cout<<std::endl;

    std::cout<<"Doggo:"<<std::endl;
    Dog doggo("Cookies","Male",3,false,"./doggo.jpg",4,"long","black");
    doggo.printInfo();
    std::cout<<std::endl;

    std::cout<<"Default doggo:"<<std::endl;
    Dog assignDoggo;
    assignDoggo.printInfo();
    std::cout<<std::endl;

    std::cout<<"Copy assignment operator assigned doggo to assignDoggo:"<<std::endl;
    assignDoggo = doggo;
    assignDoggo.printInfo();
    std::cout<<std::endl;

    std::cout<<"Trying to assign the same dog"<<std::endl;
    assignDoggo = assignDoggo;
    assignDoggo.printInfo();
    std::cout<<std::endl;



    return 0;
}