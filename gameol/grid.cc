#include "grid.h"
#include "textdisplay.h"
#include <vector>

Grid::~Grid() {
        delete td;
}

// Grid is initially empty. Sets up a TextDisplay observer when init() is called
// and the grid is initialized with cell objects.
/*
   class Grid {
    TextDisplay *td = nullptr;         // The text display is an observer on each cell.
    Observer    *ob = nullptr;         // Graphical display observer attached to each cell.
                                       // Depending upon implementation, may want to make this a
                                       // pointer to GraphicalDisplay object.
   std::vector<std::vector<Cell> > vec_cells;
   ..................
 */

void Grid::init( size_t n ){
        if (td) {
                delete td;
        }
        vec_cells.resize(n); // could probs do without resize
        td = new TextDisplay(n);

        for (size_t i = 0; i < n; i++) {
                //vec_cells.at(i).resize(n);
                for (size_t j = 0; j < n; j++) {
                        Cell c{i, j};
                        c.attach(td);   // a first observer
                        vec_cells.at(i).emplace_back(c);
                }
        }
        /// sets the neighbors
        int nm = (int)n;
        for (int i = 0; i < nm; i++) {
                for (int j = 0; j < nm; j++) {
                        // at 3 levels. i-1, i, i+1
                        int count = 0;
                        for (int k = i-1; k < i+2; k++) {
                                for (int l=j-1; l<j+2; l++ ) {
                                        //std::cout << "l : " << l << "k : "  << k << std::endl;
                                        //std::cout << nm << std::endl;

                                        if (( l < 0) || (l >= nm) || ( k < 0) || (k >= nm) || (l == j && k == i)) {
                                        } else {
                                                vec_cells[i][j].attach(&vec_cells[k][l]);
                                                //std::cout << '\t' << "(" << l << ", "  << k  << ")"<< std::endl;
                                                count++;
                                        }
                                }
                        }
                        //std::cout << "at : (" << i << ", "  << j  << ") nbrs: " <<  count<< std::endl;
                        //std::cout << std::endl;
                }
        }
} // Sets up an n x n grid.  Clears old grid, if necessary.


void Grid::turnOn( size_t r, size_t c ) {
        vec_cells[r][c].setLiving();
        td->notify(vec_cells[r][c]);
}

void Grid::tick(){
        for (auto x : vec_cells) {
                for (auto y : x) {
                        y.notify(); // notify your neighbours
                }
        }
        for (auto x : vec_cells) {
                for (auto y : x) {
                        y.recalculate();
                }
        }
        for (auto x : vec_cells) {
                for (auto y : x) {
                        td->notify(y);
                }
        }
}                        // Next tick of the simulation.


// Uses the TextDisplay to output the grid information.
std::ostream & operator<<( std::ostream & out, const Grid & g ) {
        //g.tick();
        out << *(g.td) << std::endl;
        return out;
}
