#ifndef CELL_H
#define CELL_H
#include <cstddef> // defines size_t i.e. an unsigned int
#include <iostream>
#include "subject.h"
#include "observer.h"
#include "info.h"

class Cell : public Subject, public Observer {
private:
// it has a Subject and an Observer both abstract
size_t r,c;
Info inf; //
int alive_nbrs;

public:
Cell(size_t r, size_t c);
void setLiving();     // Marks cell as alive.
void reset();     // Resets neighbour count to 0.

// Grid calls this to get me to notify my neighbours if I'm alive.
// Also needs to be called when state is set to be alive so displays are notified.
virtual void notify() override;

// My neighbours will call this to let me know if they're alive.
void notify( Subject & whoNotified ) override;

// Reassess my living-or-dead status, based on info from neighbours.
void recalculate();

// Observer calls this to get information about cell.
virtual Info getInfo() const override;
};

#endif
