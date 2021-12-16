#include <../inc/Lock.hpp>

Lock::Lock(std::mutex *pm)
{ 
    mutexPtr = pm;
    lock();
    isLocked = true;
} 

Lock::~Lock() 
{ 
    unlock();
    isLocked = false;
} 

void Lock::lock()
{
    if(isLocked == false)
    {
        mutexPtr->lock(); //aquire resource
        std::cout<<"Locked"<<std::endl;
    }
    else
    {
        std::cout<<"Already locked!!"<<std::endl;
    }
}

void Lock::unlock()
{
    if(isLocked == true)
    {
        mutexPtr->unlock(); // release resource 
        std::cout<<"Unlocked"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"Already unlocked!!"<<std::endl;
    }
}

