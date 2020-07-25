#include "subject.h"
#include "observer.h"
#include <iostream>

void Subject::attach(Observer *o) {
        observers.emplace_back(o);
}

/*
   void Subject::notifyObservers() {
        for (auto &ob : observers) ob->notify( *this );
   }*/


void Subject::notifyObservers() {
        //std::cout << "Point (" << this->getInfo().row << ", " << this->getInfo().col << ")";
        //std::cout << " notifies: " << std::endl;
        for (auto &ob : observers) {
                ob->notify( *this );
                //      std::cout << ob << std::endl;
        }
}
