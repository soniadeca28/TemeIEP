#include <iostream>
#include <memory>
#include <mutex>
#include<thread>
#include <../inc/Pet.hpp>
#include <../inc/Cat.hpp>
#include <../inc/Dog.hpp>
#include <../inc/Lock.hpp>

Cat *createCat()
{
    return new Cat("Mrs. Paw","Female",2,false,"./kitty.jpg",true,"short","white");
}

Dog *createDog()
{
    return new Dog("Cookies","Male",3,false,"./doggo.jpg",4,"long","black");
}

void takeOnMission(std::string name, std::mutex *pm)
{
    Lock lockMission(pm);
    
    //lockMission.lock(); Already locked message

    std::cout<<name<<" is now on a mission"<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
}


int main()
{
    {
        std::shared_ptr<Dog> policeDogPoliceMan1(createDog()); //A police dog can be shared within the police station.
        std::cout<<"This is a police dog.Policeman1 is now in charge of him: "<<std::endl;
        policeDogPoliceMan1->printInfo();

        std::shared_ptr<Dog> policeDogPoliceMan2(policeDogPoliceMan1); //copy so now both policemen share the dog
        std::cout<<"Policeman1 and Policeman2 now share the dog: "<<std::endl;
        policeDogPoliceMan2->printInfo();
        std::shared_ptr<std::mutex> pm = std::make_shared<std::mutex>();

        std::thread mission1(takeOnMission,policeDogPoliceMan1->getName(),pm.get()); //smart ptr get() --> stored raw ptr
        std::thread mission2(takeOnMission,policeDogPoliceMan2->getName(),pm.get());

        mission1.join();
        mission2.join();
    }

    {
        std::unique_ptr<Cat> catOldLady1(createCat()); //This cat has a single owner: the old lady
        std::cout<<"This cat is owned by an old lady: "<<std::endl;
        catOldLady1->printInfo();

        std::unique_ptr<Cat> catOldLady2 = std::move(catOldLady1); //we can only move cat to the other lady
        //std::unique_ptr<Cat> catOldLady2(catOldLady1); --> this can't be done with unique pointers
                                                      // --> the cat can only have one owner
        std::cout<<"The cat has been moved to another old lady: "<<std::endl;
        catOldLady2->printInfo();
    }
 
   

    //T2
    // Dog doggo1("Cookies","Male",3,false,"./doggo.jpg",4,"long","black");
    // Dog doggo2("Cookies","Female",4,false,"./doggo2.jpg",4,"long","golden");
    // Dog doggo3;
    // Cat cat1("Mrs. Paw","Female",2,false,"./kitty.jpg",true,"short","white");
    // Cat cat2;

    // std::cout<<std::endl;

    // std::cout<<"Chain of assignments with doggo"<<std::endl;
    // doggo3 = doggo1 = doggo2; //ITEM 10

    // std::cout<<"Doggo 1:"<<std::endl;
    // doggo1.printInfo();

    // std::cout<<"Doggo 2:"<<std::endl;
    // doggo2.printInfo();

    // std::cout<<"Doggo 3:"<<std::endl;
    // doggo3.printInfo();


    // std::cout<<"Trying to assign the same dog"<<std::endl;
    // doggo3 = doggo3; // ITEM11
    // doggo3.printInfo();
    

    // std::cout<<"Cat through copy assignment operator:"<<std::endl;
    // cat1= cat2; //ITEM12
    // cat1.printInfo();
    // std::cout<<std::endl;


    //T1
    // std::cout<<"Kitty:"<<std::endl;
    // Cat kitty("Mrs. Paw","Female",2,false,"./kitty.jpg",true,"short","white");
    // kitty.printInfo();
    // std::cout<<std::endl;
    
    // std::cout<<"Copy cat through copy constructor:"<<std::endl;
    // Cat copyCat(kitty);
    // copyCat.printInfo();
    // std::cout<<std::endl;

    // std::cout<<"Trying to assign the same cat"<<std::endl;
    // copyCat= copyCat;
    // copyCat.printInfo();
    // std::cout<<std::endl;

    // std::cout<<"Doggo:"<<std::endl;
    // Dog doggo("Cookies","Male",3,false,"./doggo.jpg",4,"long","black");
    // doggo.printInfo();
    // std::cout<<std::endl;
    
    // std::cout<<"Default doggo:"<<std::endl;
    // Dog assignDoggo;
    // assignDoggo.printInfo();
    // std::cout<<std::endl;

    // std::cout<<"Copy assignment operator assigned doggo to assignDoggo:"<<std::endl;
    // assignDoggo = doggo;
    // assignDoggo.printInfo();
    // std::cout<<std::endl;

    // std::cout<<"Trying to assign the same dog"<<std::endl;
    // assignDoggo = assignDoggo;
    // assignDoggo.printInfo();
    // std::cout<<std::endl;


    return 0;
}