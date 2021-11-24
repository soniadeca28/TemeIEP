#include <iostream>
#include <../inc/Pet.hpp>
#include <../inc/Cat.hpp>
#include <../inc/Dog.hpp>

int main()
{
    /*std::cout<<"Kitty:"<<std::endl;
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
    */
    Dog doggo1("Cookies","Male",3,false,"./doggo.jpg",4,"long","black");
    Dog doggo2("Cookies","Female",4,false,"./doggo2.jpg",4,"long","golden");
    Dog doggo3;
    Cat cat1("Mrs. Paw","Female",2,false,"./kitty.jpg",true,"short","white");
    Cat cat2;

    std::cout<<std::endl;

    std::cout<<"Chain of assignments with doggo"<<std::endl;
    doggo3 = doggo1 = doggo2; //ITEM 10

    std::cout<<"Doggo 1:"<<std::endl;
    doggo1.printInfo();

    std::cout<<"Doggo 2:"<<std::endl;
    doggo2.printInfo();

    std::cout<<"Doggo 3:"<<std::endl;
    doggo3.printInfo();


    std::cout<<"Trying to assign the same dog"<<std::endl;
    doggo3 = doggo3; // ITEM11
    doggo3.printInfo();
    

    std::cout<<"Cat through copy assignment operator:"<<std::endl;
    cat1= cat2; //ITEM12
    cat1.printInfo();
    std::cout<<std::endl;


    return 0;
}