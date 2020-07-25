#include "textdisplay.h"
#include "cell.h"
/*
   class TextDisplay : public Observer {
   ..... Cell *subject;     // subject being observed
   ..... std::vector<std::vector<char> > theDisplay;
   // how will you get notified

 */
TextDisplay::TextDisplay( size_t n ){
        theDisplay.resize(n);
        for (int i = 0; i < n; i++) {
                theDisplay.at(i).resize(n);
                for (int j = 0; j < n; j++) {
                        theDisplay[i][j] = '_';
                }
        }
}

void TextDisplay::notify( Subject & whoNotified ){
        size_t row = whoNotified.getInfo().row;
        size_t col = whoNotified.getInfo().col;
        if (whoNotified.getInfo().state == State::Dead) {
                theDisplay[row][col] = '_';
        } else {
                theDisplay[row][col] = 'X';
        }
}

// does NOTHING
void TextDisplay::notify() {
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
        int len = td.theDisplay.size();
        for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                        out << td.theDisplay.at(i).at(j);
                }
                if (i != len-1) {
                        out <<  std::endl;
                }
        }
        return out;
}
