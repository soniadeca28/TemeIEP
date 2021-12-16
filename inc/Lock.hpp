#ifndef LOCK_HPP
#define LOCK_HPP

#include<iostream>
#include <memory>
#include <mutex>

class Lock {
public:
explicit Lock(std::mutex *pm);
~Lock();
void lock();
void unlock();
private:
bool isLocked;
Lock(const Lock &lock) = delete; //prohibited copy constr
Lock &operator=(const Lock &lock) = delete; //prohibited copy assignment
std::mutex *mutexPtr;

};

#endif