#include "cell.h"
#include <iostream>
/*
   class Cell : public Subject, public Observer {
   ...
   private:
   int r,c;
   Info inf; //
   ........................................
   SUBJECT : has list of obervers
   std::vector<Observer*> observers;
   ...
   void attach(Observer *o);
   void notifyObservers();
   virtual Info getInfo() const = 0;
   .........................................
   OBSERVER :
   NOTHING ---
   // Pass the Subject that called the notify method.
   virtual void notify( Subject & whoNotified ) = 0;
   virtual void notify() = 0;

 */

Cell::Cell(size_t r, size_t c) :
        r{r}, c{c},
        inf{State::Dead, r, c}, alive_nbrs{0} {
}

void Cell::setLiving() {
        inf.state = State::Alive;
}     // Marks cell as alive.

void Cell::reset(){
        //observers.clear()
        alive_nbrs = 0;
}     // Resets neighbour count to 0.

// Grid calls this to get me to notify my neighbours if I'm alive.
// Also needs to be called when state is set to be alive so displays are notified.
//virtual void notify() override;
void Cell::notify(){
        notifyObservers();          // this is polymorphic
}

// My neighbours will call this to let me know if they're alive.
void Cell::notify(Subject & whoNotified) {
        if (inf.state == State::Alive) {
                alive_nbrs++;
        }
}

// Reassess my living-or-dead status, based on info from neighbours.
void Cell::recalculate() {
        // I'm alive
        std::cout << "Cell at " << "(" << inf.row << ", "<< inf.col << ") has #nbrs = ";
        std::cout << alive_nbrs << std::endl;
        std::string mystate = (inf.state == State::Alive) ? "Alive" : "ded";
        std::cout << '\t' << "I'm :" << mystate << std::endl;
        if (inf.state == State::Alive) {
                if (alive_nbrs == 2 || alive_nbrs == 3) {
                        // continue living
                } else {
                        inf.state = State::Dead;
                }
        } else {
                // im ded
                if (alive_nbrs == 3) {
                        inf.state = State::Alive;
                }
        }
        mystate = (inf.state == State::Alive) ? "Alive" : "ded";
        std::cout << '\t' << "I'm :" << mystate << std::endl;

        alive_nbrs = 0;
        notify();
}

// Observer calls this to get information about cell.
//virtual Info getInfo() const override;
Info Cell::getInfo() const {
        return inf;
}
