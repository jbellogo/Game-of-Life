#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <cstddef> // defines size_t i.e. an unsigned int
#include <iostream>
#include <vector>
#include "observer.h"

class Cell;

// THIS IS AN OBSERVER OF CELLS

class TextDisplay : public Observer {
Cell *subject;    // subject being observed
// observer on each cell
std::vector<std::vector<char> > theDisplay;

public:
explicit TextDisplay( size_t n );
virtual void notify( Subject & whoNotified ) override;
virtual void notify() override;

friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

#endif
