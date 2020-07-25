#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "info.h"

// DO NOT MODIFY THIS FILE!

class Observer;

class Subject {
    std::vector<Observer*> observers;

  public:
    void attach(Observer *o);  
    void notifyObservers();
    virtual Info getInfo() const = 0;
};

#endif
