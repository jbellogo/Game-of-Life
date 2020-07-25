#include <iostream>
#include <string>
// You may include other allowed headers, as needed
#include "grid.h"
#include "info.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main() {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    Grid g;

    // Add necessary code.

    try {
        while ( std::cin >> cmd ) {
            if (cmd == "new") {
                int n;
                std::cin >> n; 
                g.init(n);
            } else if (cmd == "init") {
                int x, y;
                for (std::cin >> x >> y; x >= 0; std::cin >> x >> y) {
                    g.turnOn(x ,y);
                } 
            } else if ( cmd == "step" ) {
                g.tick();
            } else if ( cmd == "steps" ) {
                int n;
                std::cin >> n;
                for ( int i = 0; i < n; ++i ) g.tick();
            } else if ( cmd == "print" ) {
                std::cout << g;
            } // if
        } // while
    } catch (ios::failure &) {}  // Any I/O failure quits
} // main
